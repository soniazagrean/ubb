package repository;

import domain.Order;
import domain.Product;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;

public class OrderFactory implements Factory<Order> {

    private final IRepository<Product> productRepo;

    public OrderFactory(IRepository<Product> productRepo) {
        this.productRepo = productRepo;
    }

    @Override
    public Order fromTokens(String[] tokens) {
        if (tokens.length < 2) throw new IllegalArgumentException("Invalid order format");
        int id = Integer.parseInt(tokens[0].trim());
        LocalDate date = LocalDate.parse(tokens[1].trim());
        Order order = new Order(id);
        order.setDate(date);
        if (tokens.length >= 3) parseProductIds(order, tokens[2]);
        return order;
    }

    @Override
    public String toLine(Order order) {
        return order.getId() + ";" + order.getDate() + ";" + getProductIdsString(order);
    }

    @Override
    public Order createFromResultSet(ResultSet rs) throws SQLException {
        int id = rs.getInt("id");
        String dateStr = rs.getString("date");
        String productIdsStr = rs.getString("product_ids");

        Order order = new Order(id);
        if (dateStr != null) {
            order.setDate(LocalDate.parse(dateStr));
        }

        if (productIdsStr != null && !productIdsStr.isEmpty()) {
            parseProductIds(order, productIdsStr);
        }
        return order;
    }

    private void parseProductIds(Order order, String idsString) {
        String[] productIds = idsString.split(",");
        for (String pidStr : productIds) {
            try {
                if (!pidStr.trim().isEmpty()) {
                    int pid = Integer.parseInt(pidStr.trim());
                    Product p = productRepo.findById(pid);
                    if (p != null) order.addProduct(p);
                }
            } catch (NumberFormatException ignored) {
            }
        }
    }

    public String getProductIdsString(Order order) {
        StringBuilder sb = new StringBuilder();
        var products = order.getProducts();
        for (int i = 0; i < products.size(); i++) {
            sb.append(products.get(i).getId());
            if (i < products.size() - 1) sb.append(",");
        }
        return sb.toString();
    }
}