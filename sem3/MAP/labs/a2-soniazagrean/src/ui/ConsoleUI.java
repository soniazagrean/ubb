import java.time.LocalDate;
import java.util.Scanner;

public class ConsoleUI {
    private final ProductService productService;
    private final OrderService orderService;
    private final IdGenerator productIdGen;
    private final IdGenerator orderIdGen;
    private final Scanner sc = new Scanner(System.in);

    public ConsoleUI(ProductService productService, OrderService orderService, IdGenerator productIdGen, IdGenerator orderIdGen) {
        this.productService = productService;
        this.orderService = orderService;
        this.productIdGen = productIdGen;
        this.orderIdGen = orderIdGen;
    }

    public void start() {
        while (true) {
            printMenu();
            System.out.print("Choose option: ");
            String option = sc.nextLine();

            try {
                switch (option) {
                    case "1" -> listProducts();
                    case "2" -> addProduct();
                    case "3" -> deleteProduct();
                    case "4" -> listOrders();
                    case "5" -> createOrder();
                    case "6" -> updateProduct();
                    case "0" -> {
                        System.out.println("Exiting... bye!");
                        sc.close();
                        return;
                    }
                    default -> System.out.println("Invalid option, try again.");
                }
            } catch (RuntimeException ex) {
                System.out.println("Error: " + ex.getMessage());
            }
        }
    }

    private void printMenu() {
        System.out.println("\n Electronics Store Menu");
        System.out.println("1. List all products");
        System.out.println("2. Add product");
        System.out.println("3. Delete product");
        System.out.println("4. List all orders");
        System.out.println("5. Create order");
        System.out.println("6. Update product");
        System.out.println("0. Exit");
    }

    private void listProducts() {
        var products = productService.getAllProducts();
        if (products.isEmpty())
            System.out.println("No products available.");
        else
            products.forEach(System.out::println);
    }

    private void addProduct() {
        System.out.print("Category: ");
        String cat = sc.nextLine();
        System.out.print("Name: ");
        String name = sc.nextLine();
        System.out.print("Price: ");
        int price = Integer.parseInt(sc.nextLine());

        if (name == null || name.isBlank()) {
            System.out.println("Product name cannot be empty. Product not added.");
            return;
        }

        int nextId = productIdGen.peekNext();
        Product p = new Product(nextId, cat, name, price);

        try {
            productService.addProduct(p);
            productIdGen.consumeNext();
            System.out.println("Product added: " + p);
        } catch (DuplicateIdException e) {
            System.out.println("Duplicate ID found. Product not added.");
        }
    }


    private void deleteProduct() {
        System.out.print("Enter product ID to delete: ");
        int id = Integer.parseInt(sc.nextLine());
        productService.deleteProduct(id);
        System.out.println("Product deleted.");
    }

    private void listOrders() {
        var orders = orderService.getAllOrders();
        if (orders.isEmpty())
            System.out.println("No orders available.");
        else
            orders.forEach(System.out::println);
    }

    private void createOrder() {
        System.out.println("Enter product IDs separated by commas: ");
        String[] parts = sc.nextLine().split(",");

        int nextId = orderIdGen.peekNext();
        Order newOrder = new Order(nextId);

        for (String part : parts) {
            try {
                int pid = Integer.parseInt(part.trim());
                Product pr = productService.getProduct(pid);
                if (pr != null)
                    newOrder.addProduct(pr);
            } catch (NumberFormatException e) {
                System.out.println("Invalid ID: " + part);
            }
        }

        newOrder.setDate(LocalDate.now());

        try {
            orderService.addOrder(newOrder);
            orderIdGen.consumeNext();
            System.out.println("Order created: " + newOrder);
        } catch (RuntimeException e) {
            System.out.println("Order creation failed: " + e.getMessage());
        }
    }


    private void updateProduct() {
        System.out.print("Enter product ID to update: ");
        int id = Integer.parseInt(sc.nextLine());
        Product existing = productService.getProduct(id);
        if (existing == null) {
            System.out.println("Product not found!");
            return;
        }

        System.out.print("New category (leave empty to keep '" + existing.getCategory() + "'): ");
        String cat = sc.nextLine();
        if (!cat.isBlank())
            existing.setCategory(cat);

        System.out.print("New name (leave empty to keep '" + existing.getName() + "'): ");
        String name = sc.nextLine();
        if (!name.isBlank())
            existing.setName(name);

        System.out.print("New price (leave empty to keep '" + existing.getPrice() + "'): ");
        String priceInput = sc.nextLine();
        if (!priceInput.isBlank()) {
            try {
                existing.setPrice(Integer.parseInt(priceInput));
            } catch (NumberFormatException e) {
                System.out.println("Invalid price, keeping old value.");
            }
        }

        productService.updateProduct(existing);
        System.out.println("Product updated: " + existing);
    }
}
