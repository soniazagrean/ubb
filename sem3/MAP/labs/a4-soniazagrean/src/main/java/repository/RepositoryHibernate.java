package repository;

import domain.Entity;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

import java.util.ArrayList;
import java.util.List;

public class RepositoryHibernate<T extends Entity> implements IRepository<T> {

    private final Class<T> type;
    private static SessionFactory sessionFactory;

    public RepositoryHibernate(Class<T> type) {
        this.type = type;
        if (sessionFactory == null) {
            try {
                sessionFactory = new Configuration().configure().buildSessionFactory();
            } catch (Exception e) {
                System.err.println("Hibernate Init Failed: " + e.getMessage());
            }
        }
    }

    @Override
    public void addElement(T element) {
        try (Session session = sessionFactory.openSession()) {
            Transaction tx = session.beginTransaction();
            session.merge(element);
            tx.commit();
        }
    }

    @Override
    public void deleteElement(Integer id) {
        try (Session session = sessionFactory.openSession()) {
            Transaction tx = session.beginTransaction();
            T item = session.get(type, id);
            if (item != null) session.remove(item);
            tx.commit();
        }
    }

    @Override
    public void updateElement(T newElement) {
        try (Session session = sessionFactory.openSession()) {
            Transaction tx = session.beginTransaction();
            session.merge(newElement);
            tx.commit();
        }
    }

    @Override
    public T findById(int id) {
        try (Session session = sessionFactory.openSession()) {
            return session.get(type, id);
        }
    }

    @Override
    public ArrayList<T> getAll() {
        try (Session session = sessionFactory.openSession()) {
            List<T> list = session.createQuery("from " + type.getName(), type).list();
            return new ArrayList<>(list);
        }
    }

    @Override
    public boolean ifExists(int id) {
        return findById(id) != null;
    }

    @Override
    public void deleteElement(T element) {
        deleteElement(element.getId());
    }

    @Override
    public int size() {
        return getAll().size();
    }

    @Override
    public void clear() {
        try (Session session = sessionFactory.openSession()) {
            Transaction tx = session.beginTransaction();
            session.createMutationQuery("delete from " + type.getName()).executeUpdate();
            tx.commit();
        }
    }
}