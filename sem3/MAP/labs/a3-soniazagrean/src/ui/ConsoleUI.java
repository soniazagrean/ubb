import java.time.LocalDate;
import java.util.Scanner;

public class ConsoleUI {

    private final ProductService productService;
    private final OrderService orderService;
    private final IdGenerator productIdGen;
    private final IdGenerator orderIdGen;

    private final Scanner sc = new Scanner(System.in);

    public ConsoleUI(ProductService productService,
                     OrderService orderService,
                     IdGenerator productIdGen,
                     IdGenerator orderIdGen) {

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
                        System.out.println("Exiting... Bye!");
                        return;
                    }
                    default -> System.out.println("Invalid option.");
                }
            } catch (RuntimeException ex) {
                System.out.println("Error: " + ex.getMessage());
            }
        }
    }

    // -------------------------
    // MENU
    // -------------------------
    private void printMenu() {
        System.out.println("\nElectronics Store Menu");
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
        int price;

        try {
            price = Integer.parseInt(sc.nextLine());
        } catch (NumberFormatException e) {
            System.out.println("Invalid price. Product not added.");
            return;
        }

        if (name.isBlank()) {
            System.out.println("Product name cannot be empty.");
            return;
        }

        int nextId = productIdGen.peekNext();
        Product p = new Product(nextId, cat, name, price);

        try {
            productService.addProduct(p);
            productIdGen.consumeNext();
            System.out.println("Product added: " + p);
        } catch (Exception ex) {
            System.out.println("Could not add product: " + ex.getMessage());
        }
    }

    private void deleteProduct() {
        System.out.print("Enter product ID to delete: ");
        try {
            int id = Integer.parseInt(sc.nextLine());
            productService.deleteProduct(id);
            System.out.println("Product deleted.");
        } catch (NumberFormatException e) {
            System.out.println("Invalid ID.");
        }
    }

    private void updateProduct() {
        System.out.print("Enter product ID to update: ");
        int id;

        try {
            id = Integer.parseInt(sc.nextLine());
        } catch (NumberFormatException e) {
            System.out.println("Invalid ID.");
            return;
        }

        Product existing = productService.getProduct(id);

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
                System.out.println("Invalid price, old price kept.");
            }
        }

        productService.updateProduct(existing);
        System.out.println("Product updated: " + existing);
    }

    private void listOrders() {
        var orders = orderService.getAllOrders();
        if (orders.isEmpty())
            System.out.println("No orders available.");
        else
            orders.forEach(System.out::println);
    }

    private void createOrder() {
        System.out.println("Enter product IDs separated by commas:");
        String[] parts = sc.nextLine().split(",");

        int nextId = orderIdGen.peekNext();
        Order newOrder = new Order(nextId);

        for (String p : parts) {
            try {
                int pid = Integer.parseInt(p.trim());
                Product pr = productService.getProduct(pid);
                newOrder.addProduct(pr);
            } catch (Exception e) {
                System.out.println("Invalid product ID: " + p);
            }
        }

        newOrder.setDate(LocalDate.now());

        try {
            orderService.addOrder(newOrder);
            orderIdGen.consumeNext();
            System.out.println("Order created: " + newOrder);
        } catch (Exception ex) {
            System.out.println("Failed to create order: " + ex.getMessage());
        }
    }
}
