

import domain.Order;
import domain.Product;
import org.junit.jupiter.api.Test;

import java.time.LocalDate;

import static org.junit.jupiter.api.Assertions.*;

public class OrderTest {

    @Test
    void testOrderCreationAndProducts() {
        Order order = new Order(1);
        assertEquals(1, order.getId());
        assertTrue(order.getProducts().isEmpty());

        Product p1 = new Product(1, "phone", "iPhone", 999);
        Product p2 = new Product(2, "laptop", "MacBook", 1999);

        order.addProduct(p1);
        order.addProduct(p2);

        assertEquals(2, order.getProducts().size());
        assertTrue(order.getProducts().contains(p1));
        assertTrue(order.getProducts().contains(p2));

        order.setDate(LocalDate.of(2025, 11, 25));
        assertEquals(LocalDate.of(2025, 11, 25), order.getDate());
    }

    @Test
    void testEqualsAndHashCode() {
        Order o1 = new Order(1);
        Order o2 = new Order(1);
        Order o3 = new Order(2);

        assertEquals(o1, o2);
        assertNotEquals(o1, o3);
    }

    @Test
    void testToString() {
        Order o = new Order(1);
        o.addProduct(new Product(1, "phone", "iPhone", 999));
        String s = o.toString();
        assertTrue(s.contains("iPhone"));
        assertTrue(s.contains("1"));
    }
}
