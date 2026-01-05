package repository;

import com.mongodb.client.*;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.ReplaceOptions;
import domain.Entity;
import domain.Order;
import domain.Product;
import org.bson.Document;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class RepositoryMongo<T extends Entity> implements IRepository<T> {
    private final MongoCollection<Document> collection;
    private final Class<T> type;

    public RepositoryMongo(Class<T> type, String connString, String dbName, String colName) {
        this.type = type;
        MongoClient client = MongoClients.create(connString);
        MongoDatabase db = client.getDatabase(dbName);
        this.collection = db.getCollection(colName);
    }

    @Override
    public void addElement(T element) {
        collection.insertOne(toDocument(element));
    }

    @Override
    public void updateElement(T newElement) {
        collection.replaceOne(Filters.eq("_id", newElement.getId()), toDocument(newElement), new ReplaceOptions().upsert(true));
    }

    @Override
    public void deleteElement(Integer id) {
        collection.deleteOne(Filters.eq("_id", id));
    }

    @Override
    public ArrayList<T> getAll() {
        ArrayList<T> list = new ArrayList<>();
        for (Document doc : collection.find()) {
            T entity = fromDocument(doc);
            if (entity != null) list.add(entity);
        }
        return list;
    }

    @Override
    public T findById(int id) {
        Document doc = collection.find(Filters.eq("_id", id)).first();
        return (doc == null) ? null : fromDocument(doc);
    }

    private Document toDocument(T entity) {
        Document doc = new Document("_id", entity.getId());

        if (entity instanceof Product p) {
            doc.append("category", p.getCategory())
                    .append("name", p.getName())
                    .append("price", p.getPrice());
        } else if (entity instanceof Order o) {
            doc.append("date", o.getDate().toString());

            // Save the full product details - embedding
            List<Document> productsList = new ArrayList<>();
            for (Product p : o.getProducts()) {
                Document prodDoc = new Document("_id", p.getId())
                        .append("category", p.getCategory())
                        .append("name", p.getName())
                        .append("price", p.getPrice());
                productsList.add(prodDoc);
            }
            doc.append("products", productsList);
        }
        return doc;
    }

    private T fromDocument(Document doc) {
        int id = doc.getInteger("_id");

        if (type == Product.class) {
            return type.cast(new Product(id,
                    doc.getString("category"),
                    doc.getString("name"),
                    doc.getInteger("price")));
        } else if (type == Order.class) {
            Order o = new Order(id);
            o.setDate(LocalDate.parse(doc.getString("date")));

            // Load the full product details back into the order
            List<Document> productsList = doc.getList("products", Document.class);
            if (productsList != null) {
                for (Document prodDoc : productsList) {
                    Product p = new Product(
                            prodDoc.getInteger("_id"),
                            prodDoc.getString("category"),
                            prodDoc.getString("name"),
                            prodDoc.getInteger("price")
                    );
                    o.addProduct(p); // Add product to the order
                }
            }
            return type.cast(o);
        }
        return null;
    }

    @Override
    public boolean ifExists(int id) {
        return findById(id) != null;
    }

    @Override
    public void deleteElement(T element) {
        deleteElement(element.getId());
    }

    @Override
    public int size() {
        return (int) collection.countDocuments();
    }

    @Override
    public void clear() {
        collection.drop();
    }
}