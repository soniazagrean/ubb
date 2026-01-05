package repository;

import domain.HealthData;

import java.util.ArrayList;

public class InMemoryRepository<T extends HealthData> implements IRepository<T> {
    ArrayList<T> elements = new ArrayList<>();

    @Override
    public void addElement(T elem) {
        elements.add(elem);
    }

    @Override
    public ArrayList<T> getAll() {
        return elements;
    }

    @Override
    public void clear() {
        elements.clear();
    }
}
