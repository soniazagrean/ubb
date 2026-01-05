import java.time.LocalDate;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Repository<Product> productRepo = new Repository<>();
        Repository<Order> orderRepo = new Repository<>();

        ProductService productService = new ProductService(productRepo);
        OrderService orderService = new OrderService(orderRepo);

        IdGenerator productIdGen = new IdGenerator("last_product_id.txt");
        IdGenerator orderIdGen = new IdGenerator("last_order_id.txt");

        productService.addProduct(new Product(productIdGen.consumeNext(), "Laptop", "Dell", 1200));
        productService.addProduct(new Product(productIdGen.consumeNext(), "Phone", "iPhone 15", 1400));
        productService.addProduct(new Product(productIdGen.consumeNext(), "Tablet", "iPad Air", 700));
        productService.addProduct(new Product(productIdGen.consumeNext(), "Accessory", "USB-C Charger", 30));
        productService.addProduct(new Product(productIdGen.consumeNext(), "Headphones", "Sony", 350));

        Order order1 = new Order(orderIdGen.consumeNext());
        order1.addProduct(productService.getAllProducts().get(0)); // Dell
        order1.addProduct(productService.getAllProducts().get(3)); // Charger
        order1.setDate(LocalDate.now().plusDays(2));
        orderService.addOrder(order1);

        Order order2 = new Order(orderIdGen.consumeNext());
        order2.addProduct(productService.getAllProducts().get(1)); // iPhone
        order2.setDate(LocalDate.now().plusDays(3));
        orderService.addOrder(order2);

        ConsoleUI ui = new ConsoleUI(productService, orderService, productIdGen, orderIdGen);
        ui.start();
    }
}
