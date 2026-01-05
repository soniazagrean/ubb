import java.util.ArrayList;

public interface RepositoryInterface<T extends Entity> {
    void addElem(T element);

    boolean ifExists(int id);

    void deleteElem(Integer id);

    ArrayList<T> getAll();

    T findById(int id);

    void updateElem(T newElement);

    int size();

    void clear();

}
