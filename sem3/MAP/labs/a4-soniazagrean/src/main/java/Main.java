import com.github.javafaker.Faker;
import domain.Order;
import domain.Product;
import repository.*;
import service.OrderService;
import service.ProductService;
import ui.ConsoleUI;
import ui.gui.HelloApplication;
import utils.IdGenerator;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Properties;

public class Main {
    public static void main(String[] args) {
        // 1. Load Settings
        Properties props = new Properties();
        try {
            Path cfg = Path.of("src/settings.properties");
            if (Files.exists(cfg)) {
                try (var in = Files.newInputStream(cfg)) {
                    props.load(in);
                }
            } else {
                System.out.println("Warning: settings.properties not found at src/settings.properties");
            }
        } catch (Exception e) {
            System.out.println("Could not read settings.properties: " + e.getMessage());
        }

        String repoType = props.getProperty("Repository", "memory").toLowerCase();
        String launchType = props.getProperty("LaunchType", "console").toLowerCase();

        String rawUrl = props.getProperty("JdbcUrl", "jdbc:sqlite:data/electronics.db");
        final String dbPath = rawUrl.replace("jdbc:sqlite:", "");

        String mongoUrl = props.getProperty("MongoUrl", "mongodb://localhost:27017");
        String mongoDbName = props.getProperty("MongoDb", "electronics_store");

        System.out.println("Repository type: " + repoType);
        System.out.println("Launch type: " + launchType);

        Path productsBin = Path.of(props.getProperty("ProductsBin", "data/product.bin"));
        Path ordersBin = Path.of(props.getProperty("OrdersBin", "data/order.bin"));
        Path ordersJson = Path.of(props.getProperty("OrdersJson", "data/order.json"));
        Path productsJson = Path.of(props.getProperty("ProductsJson", "data/product.json"));
        Path ordersXml = Path.of(props.getProperty("OrdersXml", "data/order.xml"));
        Path productsXml = Path.of(props.getProperty("ProductsXml", "data/product.xml"));
        Path productsTxt = Path.of(props.getProperty("ProductsTxt", "data/product.txt"));
        Path ordersTxt = Path.of(props.getProperty("OrdersTxt", "data/order.txt"));

        IRepository<Product> productRepo;
        IRepository<Order> orderRepo;

        try {
            productRepo = switch (repoType) {
                case "memory" -> new InMemoryRepository<>();
                case "binary" -> new RepositoryBinaryFile<>(productsBin);
                case "text" -> new RepositoryTextFile<>(productsTxt, new ProductFactory());
                case "json" -> new RepositoryJsonFile<>(productsJson, Product.class);
                case "xml" -> new RepositoryXmlFile<>(productsXml, Product.class);
                case "database" -> new RepositorySql<>(dbPath, "products", new ProductFactory());
                case "hibernate" -> new RepositoryHibernate<>(Product.class);
                case "nosql" -> new RepositoryMongo<>(Product.class, mongoUrl, mongoDbName, "products");

                default -> throw new IllegalArgumentException("Unknown repo type: " + repoType);
            };

            orderRepo = switch (repoType) {
                case "memory" -> new InMemoryRepository<>();
                case "binary" -> new RepositoryBinaryFile<>(ordersBin);
                case "text" -> new RepositoryTextFile<>(ordersTxt, new OrderFactory(productRepo));
                case "json" -> new RepositoryJsonFile<>(ordersJson, Order.class);
                case "xml" -> new RepositoryXmlFile<>(ordersXml, Order.class);
                case "database" -> new RepositorySql<>(dbPath, "orders", new OrderFactory(productRepo));
                case "hibernate" -> new RepositoryHibernate<>(Order.class);
                case "nosql" -> new RepositoryMongo<>(Order.class, mongoUrl, mongoDbName, "orders");

                default -> throw new IllegalArgumentException("Unknown repo type: " + repoType);
            };
        } catch (Exception e) {
            System.err.println("Critical Error initializing repositories: " + e.getMessage());
//            e.printStackTrace();
            return;
        }
//        if ("nosql".equals(repoType)) {
//            orderRepo.clear();
//        }

        if ("database".equals(repoType) && productRepo.getAll().isEmpty()) {
            System.out.println("Database empty. Generating 100 fake products...");
            Faker faker = new Faker();
            for (int i = 1; i <= 100; i++) {
                String category = faker.commerce().department();
                String name = faker.commerce().productName();
                String priceStr = faker.commerce().price().replaceAll("[^\\d.]", "");
                int price = (int) Double.parseDouble(priceStr);

                try {
                    productRepo.addElement(new Product(i, category, name, price));
                } catch (Exception e) {
                    System.out.println("Error adding fake product: " + e.getMessage());
                }
            }
        }

        IdGenerator productIdGen = new IdGenerator("last_product_id.txt");
        IdGenerator orderIdGen = new IdGenerator("last_order_id.txt");

        ProductService productService = new ProductService(productRepo);
        OrderService orderService = new OrderService(orderRepo);

        ConsoleUI ui = new ConsoleUI(productService, orderService, productIdGen, orderIdGen);

        switch (launchType) {
            case "console" -> ui.start();
            case "gui" -> {
                HelloApplication.setServices(productService, orderService);
                javafx.application.Application.launch(HelloApplication.class, args);
            }
            default -> System.out.println("Unknown launch type: " + launchType);
        }
    }
}