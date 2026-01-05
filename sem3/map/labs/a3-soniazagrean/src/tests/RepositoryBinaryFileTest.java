import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.io.TempDir;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

import static org.junit.jupiter.api.Assertions.*;

// Product is Serializable because it implements Serializable and extends Entity
public class RepositoryBinaryFileTest {

    @TempDir
    Path tempDir;

    private Path filePath;

    @BeforeEach
    void setUp() {
        filePath = tempDir.resolve("products.bin");
    }

    @Test
    void load_FromNonExistentFile_InitializesEmpty() {
        // File does not exist, should create it and persist an empty list
        RepositoryBinaryFile<Product> repo = new RepositoryBinaryFile<>(filePath);

        assertTrue(repo.getAll().isEmpty());
    }

    // NEW TEST: Covers the case where the file exists but is empty (size == 0)
    @Test
    void load_FromExistingEmptyFile_InitializesEmpty() throws IOException {
        Files.createFile(filePath); // Create an empty file
        // Ensure it is empty
        assertEquals(0, Files.size(filePath));

        RepositoryBinaryFile<Product> repo = new RepositoryBinaryFile<>(filePath);

        assertTrue(repo.getAll().isEmpty());
    }

    @Test
    void load_FromPopulatedFile_LoadsElements() {
        // Setup: Create a repository, add elements, and let it persist
        RepositoryBinaryFile<Product> setupRepo = new RepositoryBinaryFile<>(filePath);
        setupRepo.addElement(new Product(1, "A", "P1", 10));
        setupRepo.addElement(new Product(2, "B", "P2", 20));

        // Test: Load from the persisted file
        RepositoryBinaryFile<Product> loadRepo = new RepositoryBinaryFile<>(filePath);

        assertEquals(2, loadRepo.size());
        assertEquals("P1", loadRepo.findById(1).getName());
        assertEquals(20, loadRepo.findById(2).getPrice());
    }

    @Test
    void load_CorruptedBinaryFile_RecreatesEmptyRepo() throws IOException {
        // Write some non-serializable garbage data to the file path
        Files.writeString(filePath, "This is not a serialized object.");

        // When loading, it should hit IOException/ClassNotFoundException, clear the repo, and persist the empty state.
        RepositoryBinaryFile<Product> repo = new RepositoryBinaryFile<>(filePath);

        // Should be empty
        assertTrue(repo.getAll().isEmpty());

        // Check that the file was rewritten (by attempting a second successful load)
        RepositoryBinaryFile<Product> repo2 = new RepositoryBinaryFile<>(filePath);
        assertTrue(repo2.getAll().isEmpty());
    }

    @Test
    void persist_AddElement_SavesToFile() {
        RepositoryBinaryFile<Product> repo = new RepositoryBinaryFile<>(filePath);
        Product newProduct = new Product(3, "C", "P3", 30);

        repo.addElement(newProduct);

        // Reload from file to verify persistence
        RepositoryBinaryFile<Product> loadRepo = new RepositoryBinaryFile<>(filePath);
        assertEquals(1, loadRepo.size());
        assertEquals("P3", loadRepo.findById(3).getName());
    }

    @Test
    void persist_DeleteElement_SavesToFile() {
        // Setup: Pre-populate
        RepositoryBinaryFile<Product> setupRepo = new RepositoryBinaryFile<>(filePath);
        setupRepo.addElement(new Product(1, "A", "P1", 10));
        setupRepo.addElement(new Product(2, "B", "P2", 20));

        // Delete and persist
        setupRepo.deleteElement(1);

        // Reload from file to verify persistence
        RepositoryBinaryFile<Product> loadRepo = new RepositoryBinaryFile<>(filePath);
        assertEquals(1, loadRepo.size());
        assertNull(loadRepo.findById(1));
        assertNotNull(loadRepo.findById(2));
    }
}