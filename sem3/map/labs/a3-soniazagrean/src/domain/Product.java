import java.io.Serializable;

public class Product extends Entity implements Serializable {
    private String category;
    private String name;
    private int price;

    public Product(int id, String category, String name, int price) {
        super(id);
        this.category = category;
        this.name = name;
        this.price = price;
    }
    public Product() {}

    public String getCategory() {
        return this.category;
    }

    public String getName() {
        return this.name;
    }

    public int getPrice() {
        return this.price;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Product:{" + getId() + "," + getCategory() + "," + getName() + "," + getPrice() + "}";
    }
}
