

import domain.Order;
import domain.Product;
import exceptions.ObjectNotFoundException;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import repository.IRepository;
import repository.InMemoryRepository;
import service.OrderService;
import service.ProductService;

import java.time.LocalDate;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class OrderServiceTest {

    private OrderService orderService;
    private IRepository<Order> repo;
    private ProductService productService; // Assuming ProductService/Product exist

    @BeforeEach
    void setUp() {
        repo = new InMemoryRepository<>();
        orderService = new OrderService(repo);

        // Setup mock dependency needed for orders (assuming ProductService/Product exist)
        // Note: For true isolation, this should ideally be mocked, but InMemory is often acceptable.
        IRepository<Product> productRepo = new InMemoryRepository<>();
        productService = new ProductService(productRepo);
        productService.addProduct(new Product(1, "phone", "iPhone", 999));
        productService.addProduct(new Product(2, "laptop", "MacBook", 1999));
    }

    @Test
    void testAddOrder() {
        Order o = new Order(1);
        o.addProduct(productService.getProduct(1));
        o.setDate(LocalDate.now());

        orderService.addOrder(o);
        assertEquals(1, orderService.countOrders());
        assertEquals(o, orderService.getOrder(1));
    }

    @Test
    void testAddOrderWithoutDateThrows() {
        Order o = new Order(1);
        o.addProduct(productService.getProduct(1));
        // Date is null by default in this test setup
        assertThrows(IllegalArgumentException.class, () -> orderService.addOrder(o));
    }

    @Test
    void testDeleteOrder() {
        Order o = new Order(1);
        o.addProduct(productService.getProduct(1));
        o.setDate(LocalDate.now());
        orderService.addOrder(o);
        orderService.deleteOrder(1);
        assertEquals(0, orderService.countOrders());
    }

    // NEW TEST: Covers ObjectNotFoundException in getOrder
    @Test
    void testGetOrderNotFound() {
        assertThrows(ObjectNotFoundException.class, () -> orderService.getOrder(999));
    }

    // NEW TEST: Covers ObjectNotFoundException in deleteOrder
    @Test
    void testDeleteOrderNotFound() {
        assertThrows(ObjectNotFoundException.class, () -> orderService.deleteOrder(999));
    }

    // NEW TEST: Covers ObjectNotFoundException in updateOrder
    @Test
    void testUpdateOrderNotFound() {
        Order nonExistentOrder = new Order(999);
        nonExistentOrder.setDate(LocalDate.now()); // Date must be set to avoid validation error
        assertThrows(ObjectNotFoundException.class, () -> orderService.updateOrder(nonExistentOrder));
    }

    @Test
    void testUpdateOrder() {
        Order o = new Order(1);
        o.addProduct(productService.getProduct(1));
        o.setDate(LocalDate.now());
        orderService.addOrder(o);

        o.addProduct(productService.getProduct(2));
        orderService.updateOrder(o);

        assertEquals(2, orderService.getOrder(1).getProducts().size());
    }

    @Test
    void testGetAllOrders() {
        Order o1 = new Order(1);
        o1.addProduct(productService.getProduct(1));
        o1.setDate(LocalDate.now());
        Order o2 = new Order(2);
        o2.addProduct(productService.getProduct(2));
        o2.setDate(LocalDate.now());

        orderService.addOrder(o1);
        orderService.addOrder(o2);

        List<Order> all = orderService.getAllOrders();
        assertEquals(2, all.size());
    }
}