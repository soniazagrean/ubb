import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class RepositoryBinaryFile<T extends Entity> extends InMemoryRepository<T> {

    private final Path path;

    public RepositoryBinaryFile(Path path) {
        this.path = path;
        load();
    }

    private void load() {
        try {
            if (!Files.exists(path) || Files.size(path) == 0) {
                super.clear();
                persist();
                return;
            }

            try (ObjectInputStream in = new ObjectInputStream(Files.newInputStream(path))) {
                var list = (ArrayList<T>) in.readObject();
                super.clear();
                for (T e : list) super.addElement(e);
            }

        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error loading binary file: " + path + ", recreating");
            super.clear();
            persist();
        }
    }


    private void persist() {
        try {
            if (path.getParent() != null)
                Files.createDirectories(path.getParent());

            try (ObjectOutputStream out = new ObjectOutputStream(
                    Files.newOutputStream(path, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING))) {
                out.writeObject(super.getAll());
            }
        } catch (IOException e) {
            throw new RepositoryException("Error saving binary file: " + path, e);
        }
    }


    @Override
    public void addElement(T element) {
        super.addElement(element);
        persist();
    }

    @Override
    public void updateElement(T newElement) {
        super.updateElement(newElement);
        persist();
    }

    @Override
    public void deleteElement(Integer id) {
        super.deleteElement(id);
        persist();
    }

    @Override
    public void deleteElement(T element) {
        super.deleteElement(element);
        persist();
    }

    @Override
    public void clear() {
        super.clear();
        persist();
    }
}