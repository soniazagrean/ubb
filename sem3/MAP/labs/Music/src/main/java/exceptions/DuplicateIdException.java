package exceptions;

public class DuplicateIdException extends RepositoryException {
    public DuplicateIdException(int id) {
        super("Element with ID " + id + " already exists.");
    }
}