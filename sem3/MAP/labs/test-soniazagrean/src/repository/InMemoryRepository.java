package repository;

import domain.FlightInstrument;

import java.util.ArrayList;
import java.util.Objects;

public class InMemoryRepository<T extends FlightInstrument> implements IRepository<T> {
    ArrayList<T> elements = new ArrayList<>();

    @Override
    public void deleteElement(String code) {
        elements.removeIf(i -> Objects.equals(i.getCode(), code));
    }

    @Override
    public ArrayList<T> getAll() {
        return elements;
    }


    @Override
    public void addElement(T elem) {
        elements.add(elem);
    }
}
