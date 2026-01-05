package repository;

import domain.Entity;
import domain.Order;
import domain.Product;
import exceptions.RepositoryException;

import java.sql.*;
import java.util.ArrayList;

public class RepositorySql<T extends Entity> implements IRepository<T> {
    private final String url;
    private final Factory<T> factory;
    private final String tableName;

    public RepositorySql(String dbPath, String tableName, Factory<T> factory) {
        this.url = "jdbc:sqlite:" + dbPath;
        this.factory = factory;
        this.tableName = tableName;
        createTableIfNotExists();
    }

    private Connection connect() throws SQLException {
        return DriverManager.getConnection(url);
    }

    private void createTableIfNotExists() {
        String sql;
        if (tableName.equalsIgnoreCase("products")) {
            sql = """
                    CREATE TABLE IF NOT EXISTS products(
                        id INTEGER PRIMARY KEY, 
                        category TEXT, 
                        name TEXT, 
                        price INTEGER
                    )
                    """;
        } else if (tableName.equalsIgnoreCase("orders")) {
            // Stores product IDs as a comma-separated string (e.g., "1,5,10")
            sql = """
                    CREATE TABLE IF NOT EXISTS orders(
                        id INTEGER PRIMARY KEY, 
                        date TEXT, 
                        product_ids TEXT 
                    )
                    """;
        } else {
            throw new RepositoryException("Unsupported table name: " + tableName);
        }

        try (Connection conn = connect();
             Statement stmt = conn.createStatement()) {
            stmt.execute(sql);
        } catch (SQLException e) {
            throw new RepositoryException("Error creating table: " + tableName, e);
        }
    }

    @Override
    public void addElement(T element) {
        if (element instanceof Product p) {
            String sql = "INSERT INTO products(id, category, name, price) VALUES(?, ?, ?, ?)";
            try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
                ps.setInt(1, p.getId());
                ps.setString(2, p.getCategory());
                ps.setString(3, p.getName());
                ps.setInt(4, p.getPrice());
                ps.executeUpdate();
            } catch (SQLException e) {
                throw new RepositoryException("Error adding Product", e);
            }
        } else if (element instanceof Order o) {
            String sql = "INSERT INTO orders(id, date, product_ids) VALUES(?, ?, ?)";
            try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
                ps.setInt(1, o.getId());
                ps.setString(2, o.getDate().toString());

                // Use the Factory's helper logic to get IDs string if possible
                String ids = "";
                if (factory instanceof OrderFactory) {
                    ids = ((OrderFactory) factory).getProductIdsString(o);
                }
                ps.setString(3, ids);

                ps.executeUpdate();
            } catch (SQLException e) {
                throw new RepositoryException("Error adding Order", e);
            }
        }
    }

    @Override
    public boolean ifExists(int id) {
        String sql = "SELECT 1 FROM " + tableName + " WHERE id = ?";
        try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);
            ResultSet rs = ps.executeQuery();
            return rs.next();
        } catch (SQLException e) {
            throw new RepositoryException("Error checking existence", e);
        }
    }

    @Override
    public void deleteElement(Integer id) {
        String sql = "DELETE FROM " + tableName + " WHERE id = ?";
        try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);
            int affected = ps.executeUpdate();
            if (affected == 0) {
                throw new RepositoryException("Element with ID " + id + " not found.");
            }
        } catch (SQLException e) {
            throw new RepositoryException("Error deleting element", e);
        }
    }

    @Override
    public void deleteElement(T element) {
        deleteElement(element.getId());
    }

    @Override
    public void updateElement(T newElement) {
        if (newElement instanceof Product p) {
            String sql = "UPDATE products SET category=?, name=?, price=? WHERE id=?";
            try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
                ps.setString(1, p.getCategory());
                ps.setString(2, p.getName());
                ps.setInt(3, p.getPrice());
                ps.setInt(4, p.getId());
                int rows = ps.executeUpdate();
                if (rows == 0) throw new RepositoryException("Product ID not found: " + p.getId());
            } catch (SQLException e) {
                throw new RepositoryException("Error updating Product", e);
            }
        } else if (newElement instanceof Order o) {
            String sql = "UPDATE orders SET date=?, product_ids=? WHERE id=?";
            try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
                ps.setString(1, o.getDate().toString());

                String ids = "";
                if (factory instanceof OrderFactory) {
                    ids = ((OrderFactory) factory).getProductIdsString(o);
                }
                ps.setString(2, ids);

                ps.setInt(3, o.getId());
                int rows = ps.executeUpdate();
                if (rows == 0) throw new RepositoryException("Order ID not found: " + o.getId());
            } catch (SQLException e) {
                throw new RepositoryException("Error updating Order", e);
            }
        }
    }

    @Override
    public T findById(int id) {
        String sql = "SELECT * FROM " + tableName + " WHERE id = ?";
        try (Connection conn = connect(); PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);
            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                // Relies on factory.createFromResultSet(rs)
                return factory.createFromResultSet(rs);
            }
        } catch (SQLException e) {
            throw new RepositoryException("Error finding by ID", e);
        }
        return null;
    }

    @Override
    public ArrayList<T> getAll() {
        ArrayList<T> list = new ArrayList<>();
        String sql = "SELECT * FROM " + tableName;
        try (Connection conn = connect();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                list.add(factory.createFromResultSet(rs));
            }
        } catch (SQLException e) {
            throw new RepositoryException("Error getting all elements", e);
        }
        return list;
    }

    @Override
    public int size() {
        String sql = "SELECT COUNT(*) FROM " + tableName;
        try (Connection conn = connect();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {
            if (rs.next()) {
                return rs.getInt(1);
            }
        } catch (SQLException e) {
            throw new RepositoryException("Error getting size", e);
        }
        return 0;
    }

    @Override
    public void clear() {
        String sql = "DELETE FROM " + tableName;
        try (Connection conn = connect(); Statement stmt = conn.createStatement()) {
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RepositoryException("Error clearing table", e);
        }
    }
}