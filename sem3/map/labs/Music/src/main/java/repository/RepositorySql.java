package repository;

import domain.Music;
import exceptions.RepositoryException;

import java.sql.*;
import java.util.ArrayList;

public class RepositorySql<T extends Music> implements IRepository<T> {
    private final String url;
    private final Factory<T> factory;
    private final String tableName;

    public RepositorySql(String url, Factory<T> factory, String tableName) {
        this.url = "jdbc:sqlite:" + url;
        this.factory = factory;
        this.tableName = tableName;
        createTableIfNotExists();
    }

    private Connection connect() throws SQLException {
        return DriverManager.getConnection(url);
    }

    private void createTableIfNotExists() {
        String sql;
        if (tableName.equalsIgnoreCase("music")) {
            sql = """
                    CREATE TABLE IF NOT EXISTS music(
                        id INTEGER PRIMARY KEY,
                        band TEXT,
                        title TEXT,
                        genre TEXT,
                        time TEXT
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
        if (element instanceof Music m) {
            String sql = "INSERT INTO music(id, band, title, genre, time) VALUES (?, ?, ?, ?, ?)";
            try (Connection connection = connect(); PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                preparedStatement.setInt(1, m.getId());
                preparedStatement.setString(2, m.getBand());
                preparedStatement.setString(3,m.getTitle());
                preparedStatement.setString(4, m.getGenre());
                preparedStatement.setString(5, m.getTime());
                preparedStatement.executeUpdate();
            } catch (SQLException e) {
                throw new RuntimeException(e);
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
    public void updateElement(T newElement) {

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
