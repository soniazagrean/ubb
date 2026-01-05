import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Properties;

public class Main {
    public static void main(String[] args) {

        Properties props = new Properties();

        try {
            Path cfg = Path.of("src/settings.properties");

            if (Files.exists(cfg)) {
                try (var in = Files.newInputStream(cfg)) {
                    props.load(in);
                }
            }
        } catch (Exception e) {
            System.out.println("Nu am putut citi settings.properties: " + e.getMessage());
        }

        String repoType = props.getProperty("Repository", "memory").toLowerCase();
        System.out.println("Repository type: " + repoType);

        Path productsBin = Path.of(props.getProperty("ProductsBin", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/product.bin"));
        Path ordersBin   = Path.of(props.getProperty("OrdersBin", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/order.bin"));

        Path ordersJson = Path.of(props.getProperty("OrdersJson", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/order.json"));
        Path productsJson = Path.of(props.getProperty("ProductsJson", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/product.json"));

        Path ordersXml = Path.of(props.getProperty("OrdersXml", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/order.xml"));
        Path productsXml = Path.of(props.getProperty("ProductsXml", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/product.json"));

        Path productsTxt = Path.of(props.getProperty("ProductsTxt", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/product.txt"));
        Path ordersTxt   = Path.of(props.getProperty("OrdersTxt", "/Users/zagreansonia/Desktop/MAP/labs/a3-soniazagrean/data/order.txt"));

        IRepository<Product> productRepo = switch (repoType) {
            case "memory" -> new InMemoryRepository<>();
            case "binary" -> new RepositoryBinaryFile<>(productsBin);
            case "text"   -> new RepositoryTextFile<>(productsTxt, new ProductFactory());
            case "json"   -> new RepositoryJsonFile<>(productsJson, Product.class);
            case "xml"    -> new RepositoryXmlFile<>(productsXml, Product.class);
            default       -> throw new IllegalArgumentException("Tip repo necunoscut: " + repoType);
        };

        IRepository<Order> orderRepo = switch (repoType) {
            case "memory" -> new InMemoryRepository<>();
            case "binary" -> new RepositoryBinaryFile<>(ordersBin);
            case "text"   -> new RepositoryTextFile<>(ordersTxt, new OrderFactory(productRepo));
            case "json"   -> new RepositoryJsonFile<>(ordersJson, Order.class);
            case "xml"    -> new RepositoryXmlFile<>(ordersXml, Order.class);
            default       -> throw new IllegalArgumentException("Tip repo necunoscut: " + repoType);
        };

        IdGenerator productIdGen = new IdGenerator("last_product_id.txt");
        IdGenerator orderIdGen   = new IdGenerator("last_order_id.txt");

        ProductService productService = new ProductService(productRepo);
        OrderService orderService     = new OrderService(orderRepo);

        ConsoleUI ui = new ConsoleUI(productService, orderService, productIdGen, orderIdGen);
        ui.start();
    }
}
