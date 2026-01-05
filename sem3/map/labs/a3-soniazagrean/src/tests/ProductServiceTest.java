import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;

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
        assertEquals(p, productService.getProduct(1));
    }

    @Test
    void testAddProductWithoutNameThrows() {
        Product p = new Product(1, "phone", "", 999);
        assertThrows(IllegalArgumentException.class, () -> productService.addProduct(p));
    }

    @Test
    void testAddProductWithNullNameThrows() {
        Product p = new Product(1, "phone", null, 999);
        assertThrows(IllegalArgumentException.class, () -> productService.addProduct(p));
    }

    @Test
    void testDeleteProduct() {
        Product p = new Product(1, "phone", "iPhone", 999);
        productService.addProduct(p);
        productService.deleteProduct(1);
        assertEquals(0, productService.countProducts());
    }

    @Test
    void testUpdateProduct() {
        Product p = new Product(1, "phone", "iPhone", 999);
        productService.addProduct(p);
        p.setPrice(899);
        productService.updateProduct(p);
        assertEquals(899, productService.getProduct(1).getPrice());
    }

    @Test
    void testGetProductNotFound() {
        assertThrows(ObjectNotFoundException.class, () -> productService.getProduct(999));
    }

    @Test
    void testGetAllProducts() {
        productService.addProduct(new Product(1, "phone", "iPhone", 999));
        productService.addProduct(new Product(2, "laptop", "MacBook", 1999));
        List<Product> all = productService.getAllProducts();
        assertEquals(2, all.size());
    }
}