

import domain.Product;
import exceptions.ObjectNotFoundException;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import repository.IRepository;
import repository.InMemoryRepository;
import service.ProductService;
import static org.junit.jupiter.api.Assertions.*;

public class ProductServiceTest {

    private ProductService productService;
    private IRepository<Product> repo;

    @BeforeEach
    void setUp() {
        repo = new InMemoryRepository<>();
        productService = new ProductService(repo);
    }

    @Test
    void testAddProduct() {
        Product p = new Product(1, "phone", "iPhone", 999);
        productService.addProduct(p);
        assertEquals(1, productService.countProducts());
    }

    @Test
    void testAddProductWithoutNameThrows() {
        Product p = new Product(1, "phone", "", 999);
        assertThrows(IllegalArgumentException.class, () -> productService.addProduct(p));
    }

    @Test
    void testGetProductNotFound() {
        assertThrows(ObjectNotFoundException.class, () -> productService.getProduct(999));
    }
}