package repository;


import domain.Entity;
import exceptions.DuplicateIdException;
import exceptions.ObjectNotFoundException;

import java.util.ArrayList;

public class InMemoryRepository<T extends Entity> implements IRepository<T> {
    private final ArrayList<T> elements = new ArrayList<>();

    @Override
    public void addElement(T element) {
        if (ifExists(element.getId()))
            throw new DuplicateIdException(element.getId());
        elements.add(element);
    }

    @Override
    public boolean ifExists(int id) {
        for (T e : elements)
            if (e.getId() == id)
                return true;
        return false;
    }

    @Override
    public void deleteElement(Integer id) {
        boolean removed = elements.removeIf(e -> e.getId() == id);
        if (!removed)
            throw new ObjectNotFoundException(id);
    }

    @Override
    public ArrayList<T> getAll() {
        return new ArrayList<>(elements);
    }

    @Override
    public T findById(int id) {
        for (T e : elements)
            if (e.getId() == id)
                return e;
        return null;
    }

    @Override
    public void updateElement(T newElement) {
        for (int i = 0; i < elements.size(); i++) {
            if (elements.get(i).getId() == newElement.getId()) {
                elements.set(i, newElement);
                return;
            }
        }
        throw new ObjectNotFoundException(newElement.getId());
    }

    @Override
    public int size() {
        return elements.size();
    }

    @Override
    public void deleteElement(T element) {
        boolean ok = elements.remove(element);
        if (!ok) throw new ObjectNotFoundException(element.getId());
    }

    @Override
    public void clear() {
        elements.clear();
    }

    @Override
    public String toString() {
        return "Repository{" + elements + '}';
    }
}
