package repository;

import domain.HealthData;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.function.Function;

public class RepositoryTextFile<T extends HealthData> extends InMemoryRepository<T> {
    private final Path path;
    private final Factory<T> factory;

    public RepositoryTextFile(Path path, Factory<T> factory) {
        this.path = path;
        this.factory = factory;
//        load();
    }

    @Override
    public void addElement(T elem) {
        super.addElement(elem);
        persist();
    }

//    private void load() {
//        if (!Files.exists(path)) return; // prima rulare: nu există încă fișierul
//        try {
//            for (String line : Files.readAllLines(path)) {
//                if (line.isBlank()) continue;
//                String[] tokens = line.split(";");
//                super.addElement(factory.fromTokens(tokens));
//            }
//        } catch (IOException e) {
//            System.out.println("Eroare la citire din: " + path);
//        }
//    }

    private void persist() {
        try {
            if (path.getParent() != null) Files.createDirectories(path.getParent());
            var lines = new ArrayList<String>();
            for (T e : super.getAll()) {
                lines.add(factory.toLine(e));
            }
            Files.write(path, lines, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING);
        } catch (IOException e) {
            System.out.println("Eroare la scriere în: " + path);
        }
    }
}