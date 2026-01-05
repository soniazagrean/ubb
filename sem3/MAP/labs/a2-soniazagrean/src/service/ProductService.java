import java.util.ArrayList;

public class ProductService {
    private final Repository<Product> repo;

    public ProductService(Repository<Product> repo) {
        this.repo = repo;
    }

    public void addProduct(Product p) {
        if (p.getName() == null || p.getName().isEmpty())
            throw new IllegalArgumentException("Product name cannot be empty");
        repo.addElem(p);
    }

    public Product getProduct(int id) {
        Product p = repo.findById(id);
        if (p == null)
            throw new ObjectNotFoundException(id);
        return p;
    }

    public void deleteProduct(int id) {
        repo.deleteElem(id);
    }

    public void updateProduct(Product p) {
        repo.updateElem(p);
    }

    public ArrayList<Product> getAllProducts() {
        return repo.getAll();
    }

    public int countProducts() {
        return repo.size();
    }
}
