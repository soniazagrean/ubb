package repository;

import domain.Building;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class RepositoryBinaryFile<T extends Building> extends InMemoryRepository<T> {
    private final Path path;

    public RepositoryBinaryFile(String fileName) {
        this.path = Path.of(fileName);
//        load();
    }

    @Override
    public void addElement(T elem) {
        super.addElement(elem);
        persist();
    }

//    private void load() {
//        if (!Files.exists(path)) return;
//
//        try (ObjectInputStream in = new ObjectInputStream(Files.newInputStream(path))) {
//            Object readObject = in.readObject();
//            if (readObject instanceof List) {
//                ArrayList<T> list = (ArrayList<T>) readObject;
//                this.elements.clear();
//                this.elements.addAll(list);
//            }
//        } catch (IOException | ClassNotFoundException e) {
//            System.out.println("Error loading binary file: " + path + " (" + e.getMessage() + ")");
//        }
//    }

    private void persist() {
        try {
            if (path.getParent() != null) Files.createDirectories(path.getParent());
            try (ObjectOutputStream out = new ObjectOutputStream(Files.newOutputStream(path))) {
                out.writeObject(this.elements);
            }
        } catch (IOException e) {
            System.out.println("Error saving binary file: " + path);
        }
    }
}