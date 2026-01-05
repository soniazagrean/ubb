package repository;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule;
import domain.Entity;
import exceptions.RepositoryException;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class RepositoryJsonFile<T extends Entity> extends InMemoryRepository<T> {
    private final Path path;
    private final Class<T> type;
    private final ObjectMapper mapper = new ObjectMapper();

    public RepositoryJsonFile(Path path, Class<T> type) {
        this.path = path;
        this.type = type;
        this.mapper.registerModule(new JavaTimeModule());
        load();
    }

    private void load() {
        if (!Files.exists(path)) return;
        try {
            List<T> list = mapper.readValue(
                    Files.readAllBytes(path),
                    mapper.getTypeFactory().constructCollectionType(List.class, type)
            );
            for (T e : list) super.addElement(e);
        } catch (IOException e) {
            throw new RepositoryException("Error reading from: " + path, e);
        }
    }

    private void persist() {
        try {
            if (path.getParent() != null) Files.createDirectories(path.getParent());
            mapper.writerWithDefaultPrettyPrinter().writeValue(path.toFile(), super.getAll());
        } catch (IOException e) {
            throw new RepositoryException("Error writing to: " + path, e);
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