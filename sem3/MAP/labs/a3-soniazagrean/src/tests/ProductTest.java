import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class ProductTest {

    @Test
    void testProductCreationAndGettersSetters() {
        Product p = new Product(1, "phone", "iPhone", 999);
        assertEquals(1, p.getId());
        assertEquals("phone", p.getCategory());
        assertEquals("iPhone", p.getName());
        assertEquals(999, p.getPrice());

        // Test setters
        p.setCategory("laptop");
        p.setName("MacBook");
        p.setPrice(1999);

        assertEquals("laptop", p.getCategory());
        assertEquals("MacBook", p.getName());
        assertEquals(1999, p.getPrice());
    }

    @Test
    void testEqualsAndHashCode() {
        Product p1 = new Product(1, "phone", "iPhone", 999);
        Product p2 = new Product(1, "phone", "iPhone", 999);
        Product p3 = new Product(2, "phone", "iPhone", 999);

        assertEquals(p1, p2);
        assertNotEquals(p1, p3);

        assertEquals(p1.hashCode(), p2.hashCode());
        assertNotEquals(p1.hashCode(), p3.hashCode());
    }

    @Test
    void testToString() {
        Product p = new Product(1, "phone", "iPhone", 999);
        String s = p.toString();
        assertTrue(s.contains("iPhone"));
        assertTrue(s.contains("phone"));
        assertTrue(s.contains("999"));
    }
}
