package repository;

import domain.Entity;
import exceptions.RepositoryException;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class RepositoryTextFile<T extends Entity> extends InMemoryRepository<T> {
    private final Path path;
    private final Factory<T> factory;

    public RepositoryTextFile(Path path, Factory<T> factory) {
        this.path = path;
        this.factory = factory;
        load();
    }

    private void load() {
        if (!Files.exists(path)) return;
        try {
            for (String line : Files.readAllLines(path)) {
                if (line.isBlank()) continue;
                String[] tokens = line.split(";");
                super.addElement(factory.fromTokens(tokens));
            }
        } catch (IOException e) {
            throw new RepositoryException("Error reading from: " + path, e);
        }
    }

    private void persist() {
        try {
            if (path.getParent() != null) Files.createDirectories(path.getParent());
            var lines = new ArrayList<String>();
            for (T e : super.getAll()) {
                lines.add(factory.toLine(e));
            }
            Files.write(path, lines, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING);
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