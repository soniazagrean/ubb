import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.nio.file.Files;
import java.nio.file.Path;

import static org.junit.jupiter.api.Assertions.*;

public class IdGeneratorTest {

    private Path tempFile;
    private IdGenerator idGen;

    @BeforeEach
    void setup() throws Exception {
        // Create a temporary file unique to this test class execution
        tempFile = Files.createTempFile("last_id", ".txt");
        // Initialize the generator, causing it to call load()
        idGen = new IdGenerator(tempFile.toString());
    }

    @Test
    void testPeekAndConsumeNext() {
        int first = idGen.peekNext();
        int second = idGen.peekNext();

        assertEquals(first, second);
        int consumed = idGen.consumeNext();
        assertEquals(first, consumed);

        int next = idGen.peekNext();
        assertEquals(consumed + 1, next);
    }

    @Test
    void testPersistsId() throws Exception {
        int id = idGen.consumeNext();
        // Re-initialize generator to load the persisted ID
        IdGenerator idGen2 = new IdGenerator(tempFile.toString());
        assertEquals(id + 1, idGen2.peekNext());
    }

    // NEW TEST: Covers the NumberFormatException/IO Exception handling in IdGenerator.load()
    @Test
    void testLoad_WithInvalidContent_ResetsIdSequence() throws Exception {
        // 1. Write non-numeric content to the file, simulating corruption
        Files.writeString(tempFile, "not_a_number");

        // 2. Re-initialize the IdGenerator, forcing it to load and hit the exception handler
        // It should reset the ID to a default (usually 0) and proceed.
        IdGenerator idGen2 = new IdGenerator(tempFile.toString());

        // The generator starts at 0, so the next usable ID is 1.
        assertEquals(1, idGen2.peekNext());
    }
}