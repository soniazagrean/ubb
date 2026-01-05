import com.fasterxml.jackson.dataformat.xml.XmlMapper;
import com.fasterxml.jackson.databind.type.CollectionType;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule; // New import

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class RepositoryXmlFile<T extends Entity> extends InMemoryRepository<T> {
    private final Path path;
    private final Class<T> type;
    private final XmlMapper xmlMapper = new XmlMapper();

    public RepositoryXmlFile(Path path, Class<T> type) {
        this.path = path;
        this.type = type;
        this.xmlMapper.registerModule(new JavaTimeModule());
        load();
    }

    private void load() {
        if (!Files.exists(path)) return;
        try {
            CollectionType listType = xmlMapper.getTypeFactory().constructCollectionType(List.class, type);
            List<T> list = xmlMapper.readValue(Files.readString(path), listType);
            for (T e : list) super.addElement(e);
        } catch (IOException e) {
            throw new RepositoryException("Error reading XML from: " + path, e);
        }
    }
    private void persist() {
        try {
            if (path.getParent() != null) Files.createDirectories(path.getParent());
            xmlMapper.writerWithDefaultPrettyPrinter().writeValue(path.toFile(), super.getAll());
        } catch (IOException e) {
            throw new RepositoryException("Error writing XML to: " + path, e);
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