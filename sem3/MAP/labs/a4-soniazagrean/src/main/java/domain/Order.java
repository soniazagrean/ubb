package domain;

import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.Table;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "orders")
public class Order extends domain.Entity implements Serializable {
    @ManyToMany(fetch = FetchType.EAGER)
    private List<Product> products = new ArrayList<>();

    private LocalDate date = LocalDate.now();

    public Order(int id) {
        super(id);
    }

    public Order() {
    }

    public void addProduct(Product p) {
        products.add(p);
    }

    public List<Product> getProducts() {
        return products;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }

    @Override
    public String toString() {
        return "Order{" + getId() + "," + getDate() + "," + getProducts() + '}';
    }
}