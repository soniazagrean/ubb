package repository;

import domain.Building;

import java.util.ArrayList;

public class InMemoryRepository<T extends Building> implements IRepository<T> {
    ArrayList<T> elements = new ArrayList<>();

    @Override
    public void addElement(T elem) {
        elements.add(elem);
    }

    @Override
    public ArrayList<T> getAll() {
        return elements;
    }

}
