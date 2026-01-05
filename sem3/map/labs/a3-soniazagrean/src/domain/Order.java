import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;

public class Order extends Entity implements Serializable {
    private ArrayList<Product> products = new ArrayList<>();
    private LocalDate date = LocalDate.now();

    public Order(int id) {
        super(id);
    }

    public Order() {}

    public void addProduct(Product p) {
        products.add(p);
    }

    public ArrayList<Product> getProducts() {
        return products;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return "Order{"  + getId() + "," + getDate() + "," + getProducts() + '}';
    }
}
