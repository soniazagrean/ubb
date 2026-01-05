package repository;

import domain.Building;

import java.util.ArrayList;

public interface IRepository<T extends Building> {
    void addElement(T elem);
    ArrayList<T> getAll();
}
