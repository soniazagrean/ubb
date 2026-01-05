import java.sql.ResultSet;
import java.sql.SQLException;

public interface Factory<T> {
    T fromTokens(String[] tokens);
    String toLine(T entity);
}