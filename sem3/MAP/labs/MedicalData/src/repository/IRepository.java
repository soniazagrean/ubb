package repository;

import domain.HealthData;

import java.util.ArrayList;

public interface IRepository<T extends HealthData> {
    void addElement(T elem);
    ArrayList<T> getAll();
    void clear();
}
