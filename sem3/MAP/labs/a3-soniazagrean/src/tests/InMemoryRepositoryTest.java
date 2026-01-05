import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class InMemoryRepositoryTest {

    private InMemoryRepository<Product> repo;
    private Product product1;
    private Product product2;

    @BeforeEach
    void setUp() {
        repo = new InMemoryRepository<>();
        product1 = new Product(1, "A", "P1", 100);
        product2 = new Product(2, "B", "P2", 200);
        repo.addElement(product1);
        repo.addElement(product2);
    }

    @Test
    void addElement_NewElement_Success() {
        Product product3 = new Product(3, "C", "P3", 300);
        repo.addElement(product3);
        assertEquals(3, repo.size());
        assertTrue(repo.ifExists(3));
    }

    @Test
    void addElement_DuplicateId_ThrowsException() {
        Product duplicateProduct = new Product(1, "A", "P1_new", 150);

        assertThrows(DuplicateIdException.class, () -> {
            repo.addElement(duplicateProduct);
        });
        assertEquals(2, repo.size());
    }

    @Test
    void findById_ElementExists_ReturnsElement() {
        Product found = repo.findById(2);
        assertNotNull(found);
        assertEquals("P2", found.getName());
    }

    @Test
    void findById_ElementDoesNotExist_ReturnsNull() {
        assertNull(repo.findById(99));
    }

    @Test
    void updateElement_ElementExists_Success() {
        Product updatedProduct = new Product(1, "X", "P1_updated", 150);
        repo.updateElement(updatedProduct);

        Product found = repo.findById(1);
        assertNotNull(found);
        assertEquals("P1_updated", found.getName());
        assertEquals(150, found.getPrice());
    }

    @Test
    void updateElement_ElementDoesNotExist_ThrowsException() {
        Product nonExistentProduct = new Product(99, "X", "P99", 10);

        assertThrows(ObjectNotFoundException.class, () -> {
            repo.updateElement(nonExistentProduct);
        });
    }

    @Test
    void deleteElement_ById_Success() {
        repo.deleteElement(1);
        assertEquals(1, repo.size());
        assertFalse(repo.ifExists(1));
    }

    @Test
    void deleteElement_ByObject_Success() {
        repo.deleteElement(product2);
        assertEquals(1, repo.size());
        assertFalse(repo.ifExists(2));
    }

    @Test
    void deleteElement_NonExistingId_ThrowsException() {
        assertThrows(ObjectNotFoundException.class, () -> {
            repo.deleteElement(99);
        });
    }

    @Test
    void getAll_ReturnsCopy() {
        var all = repo.getAll();
        assertEquals(2, all.size());
        // Check that modifying the returned list doesn't affect the repository
        all.remove(0);
        assertEquals(2, repo.size());
    }

    @Test
    void clear_EmptiesRepository() {
        repo.clear();
        assertEquals(0, repo.size());
        assertTrue(repo.getAll().isEmpty());
    }
}