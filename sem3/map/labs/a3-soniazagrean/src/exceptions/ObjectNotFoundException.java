public class ObjectNotFoundException extends RepositoryException {
    public ObjectNotFoundException(int id) {
        super("Element with ID " + id + " not found.");
    }
}