

import domain.Product;
import exceptions.RepositoryException;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.io.TempDir;
import repository.ProductFactory;
import repository.RepositoryTextFile;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

import static org.junit.jupiter.api.Assertions.*;


public class RepositoryTextFileTest {

    @TempDir
    Path tempDir;

    private Path filePath;
    private ProductFactory factory;

    @BeforeEach
    void setUp() {
        filePath = tempDir.resolve("products.txt");
        factory = new ProductFactory();
    }

    @Test
    void load_FromEmptyFile_InitializesEmpty() throws IOException {
        Files.createFile(filePath);

        RepositoryTextFile<Product> repo = new RepositoryTextFile<>(filePath, factory);

        assertTrue(repo.getAll().isEmpty());
    }

    @Test
    void load_FromPopulatedFile_LoadsElements() throws IOException {
        // Prepare file content
        String content = "1;Electronics;Phone;800\n2;Food;Cookie;5";
        Files.writeString(filePath, content);

        RepositoryTextFile<Product> repo = new RepositoryTextFile<>(filePath, factory);

        assertEquals(2, repo.size());
        assertEquals("Phone", repo.findById(1).getName());
        assertEquals(5, repo.findById(2).getPrice());
    }

    // NEW TEST: Covers blank line skipping in load()
    @Test
    void load_WithBlankLines_SkipsBlankLines() throws IOException {
        // Prepare file content with blank lines and a line with only whitespace
        String content = "1;Electronics;Phone;800\n\n   \n2;Food;Cookie;5";
        Files.writeString(filePath, content);

        RepositoryTextFile<Product> repo = new RepositoryTextFile<>(filePath, factory);

        assertEquals(2, repo.size()); // Should still only load 2 products
    }

    // Assuming RepositoryException is defined in the same package/test structure
    // We keep the test for the IOException case to ensure coverage is not lost.
    @Test
    void load_FromDirectoryPath_ThrowsRepositoryException() throws IOException {
        Path directoryPath = tempDir.resolve("some_dir");
        Files.createDirectory(directoryPath);

        assertThrows(RepositoryException.class, () -> {
            new RepositoryTextFile<>(directoryPath, factory);
        });
    }

    @Test
    void persist_AddElement_SavesToFile() {
        RepositoryTextFile<Product> repo = new RepositoryTextFile<>(filePath, factory);
        Product newProduct = new Product(3, "Books", "Novel", 20);

        repo.addElement(newProduct);

        // Check file content
        try {
            String fileContent = Files.readString(filePath);
            assertTrue(fileContent.contains("3;Books;Novel;20"));
        } catch (IOException e) {
            fail("Failed to read file after persistence");
        }
    }

    @Test
    void persist_UpdateElement_SavesToFile() throws IOException {
        // Initial setup
        Files.writeString(filePath, "1;Clothes;Shirt;50");
        RepositoryTextFile<Product> repo = new RepositoryTextFile<>(filePath, factory);

        Product updatedProduct = new Product(1, "Clothes", "Shirt_updated", 60);
        repo.updateElement(updatedProduct);

        // Check file content
        try {
            String fileContent = Files.readString(filePath);
            assertTrue(fileContent.contains("1;Clothes;Shirt_updated;60"));
            assertFalse(fileContent.contains("Shirt;50"));
        } catch (IOException e) {
            fail("Failed to read file after persistence");
        }
    }

    @Test
    void persist_DeleteElement_SavesToFile() throws IOException {
        // Initial setup with two products
        String content = "1;A;P1;10\n2;B;P2;20";
        Files.writeString(filePath, content);
        RepositoryTextFile<Product> repo = new RepositoryTextFile<>(filePath, factory);

        repo.deleteElement(1);

        // Check file content
        try {
            String fileContent = Files.readString(filePath);
            assertFalse(fileContent.contains("1;A;P1;10"));
            assertTrue(fileContent.contains("2;B;P2;20"));
        } catch (IOException e) {
            fail("Failed to read file after persistence");
        }
    }
}