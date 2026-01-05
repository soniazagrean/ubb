import java.util.ArrayList;

public class OrderService {
    private final IRepository<Order> repo;

    public OrderService(IRepository<Order> repo) {
        this.repo = repo;
    }

    public void addOrder(Order o) {
        if (o.getDate() == null)
            throw new IllegalArgumentException("Order date cannot be empty");
        repo.addElement(o);
    }

    public Order getOrder(int id) {
        Order o = repo.findById(id);
        if (o == null)
            throw new ObjectNotFoundException(id);
        return o;
    }

    public void deleteOrder(int id) {
        repo.deleteElement(id);
    }

    public void updateOrder(Order o) {
        repo.updateElement(o);
    }

    public ArrayList<Order> getAllOrders() {
        return repo.getAll();
    }

    public int countOrders() {
        return repo.size();
    }
}