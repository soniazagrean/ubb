package repository;

import domain.FlightInstrument;

import java.util.ArrayList;

public interface IRepository<T extends FlightInstrument> {
    void deleteElement(String code);
    ArrayList<T> getAll();
    void addElement(T elem);
}
