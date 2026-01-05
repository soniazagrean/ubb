import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.time.LocalDate;
import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

public class OrderFactoryTest {

    private IRepository<Product> productRepo;
    private OrderFactory factory;
    private Product p1;
    private Product p2;
    private Product p3;

    @BeforeEach
    void setUp() {
        // Use InMemoryRepository for dependency (Product repository)
        productRepo = new InMemoryRepository<>();
        p1 = new Product(101, "A", "Prod1", 10);
        p2 = new Product(102, "B", "Prod2", 20);
        p3 = new Product(103, "C", "Prod3", 30);
        productRepo.addElement(p1);
        productRepo.addElement(p2);
        productRepo.addElement(p3);

        factory = new OrderFactory(productRepo);
    }

    @Test
    void fromTokens_ValidInputWithProducts_ReturnsOrder() {
        String dateString = "2023-11-25";
        // Tokens: id;date;productIds (101, 103)
        String[] tokens = {"1", dateString, "101, 103"};
        LocalDate expectedDate = LocalDate.parse(dateString);

        Order actual = factory.fromTokens(tokens);

        assertEquals(1, actual.getId());
        assertEquals(expectedDate, actual.getDate());
        assertEquals(2, actual.getProducts().size());
        assertTrue(actual.getProducts().contains(p1));
        assertTrue(actual.getProducts().contains(p3));
        assertFalse(actual.getProducts().contains(p2));
    }

    // MODIFIED TEST: Ensures the skipped NumberFormatException is covered
    @Test
    void fromTokens_InputWithMissingAndInvalidProducts_OnlyAddsValid() {
        String dateString = "2023-11-25";
        // Tokens: id;date;productIds (101, 999 (missing), 102, invalid_token_1, invalid_token_2)
        // Hitting 'invalid_token_1' and 'invalid_token_2' should cover the 'ignored' catch block.
        String[] tokens = {"2", dateString, "101,999, 102, invalid_token_1, invalid_token_2"};

        Order actual = factory.fromTokens(tokens);

        assertEquals(2, actual.getProducts().size()); // Only 101 and 102
        assertTrue(actual.getProducts().contains(p1));
        assertTrue(actual.getProducts().contains(p2));
    }

    @Test
    void fromTokens_InputWithoutProducts_ReturnsOrderWithEmptyProductList() {
        String dateString = "2023-11-25";
        // Tokens: id;date; (no product IDs)
        String[] tokens = {"3", dateString, ""}; // Ensure the tokens.length >= 3 is hit but the third token is empty

        Order actual = factory.fromTokens(tokens);

        assertEquals(3, actual.getId());
        assertTrue(actual.getProducts().isEmpty());
    }

    @Test
    void fromTokens_InvalidFormat_ThrowsException() {
        String[] tokens = {"1"}; // Missing date and products

        assertThrows(IllegalArgumentException.class, () -> {
            factory.fromTokens(tokens);
        });
    }

    @Test
    void toLine_ValidOrderWithProducts_ReturnsFormattedString() {
        Order order = new Order(10);
        order.setDate(LocalDate.of(2023, 10, 1));
        order.addProduct(p1);
        order.addProduct(p3);

        String expected = "10;2023-10-01;101,103";
        String actual = factory.toLine(order);

        assertEquals(expected, actual);
    }

    @Test
    void toLine_ValidOrderWithoutProducts_ReturnsFormattedString() {
        Order order = new Order(11);
        order.setDate(LocalDate.of(2023, 10, 2));

        String expected = "11;2023-10-02;"; // Line should end with a semicolon
        String actual = factory.toLine(order);

        assertEquals(expected, actual);
    }
}