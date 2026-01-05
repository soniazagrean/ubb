
import domain.Product;
import org.junit.jupiter.api.Test;
import repository.ProductFactory;

import static org.junit.jupiter.api.Assertions.*;

public class ProductFactoryTest {

    private final ProductFactory factory = new ProductFactory();

    @Test
    void fromTokens_ValidInput_ReturnsProduct() {
        String[] tokens = {"1", "Electronics", "Laptop", "1500"};
        Product expected = new Product(1, "Electronics", "Laptop", 1500);

        Product actual = factory.fromTokens(tokens);

        assertEquals(expected.getId(), actual.getId());
        assertEquals(expected.getCategory(), actual.getCategory());
        assertEquals(expected.getName(), actual.getName());
        assertEquals(expected.getPrice(), actual.getPrice());
    }

    @Test
    void fromTokens_InvalidLength_ThrowsException() {
        String[] tokens = {"1", "Electronics", "Laptop"}; // Missing price

        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            factory.fromTokens(tokens);
        });

        assertTrue(exception.getMessage().contains("Invalid product format"));
    }

    @Test
    void fromTokens_InvalidId_ThrowsException() {
        String[] tokens = {"one", "Electronics", "Laptop", "1500"};

        assertThrows(NumberFormatException.class, () -> {
            factory.fromTokens(tokens);
        });
    }

    // NEW TEST: Covers NumberFormatException on Price
    @Test
    void fromTokens_InvalidPrice_ThrowsException() {
        String[] tokens = {"1", "Electronics", "Laptop", "one-five-hundred"};

        assertThrows(NumberFormatException.class, () -> {
            factory.fromTokens(tokens);
        });
    }

    @Test
    void toLine_ValidProduct_ReturnsFormattedString() {
        Product product = new Product(10, "Food", "Apple", 2);
        String expected = "10;Food;Apple;2";

        String actual = factory.toLine(product);

        assertEquals(expected, actual);
    }
}