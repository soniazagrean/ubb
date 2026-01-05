package repository;

import domain.Music;

import java.util.ArrayList;

public interface IRepository<T extends Music> {
    void addElement(T element);

    boolean ifExists(int id);

    void deleteElement(Integer id);

    void deleteElement(T element);

    ArrayList<T> getAll();

    T findById(int id);

    void updateElement(T newElement);

    int size();

    void clear();

}
