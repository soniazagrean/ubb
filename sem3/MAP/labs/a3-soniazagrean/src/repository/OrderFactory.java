import java.time.LocalDate;

public class OrderFactory implements Factory<Order> {

    private final IRepository<Product> productRepo;

    public OrderFactory(IRepository<Product> productRepo) {
        this.productRepo = productRepo;
    }

    @Override
    public Order fromTokens(String[] tokens) {
        if (tokens.length < 2) {
            throw new IllegalArgumentException("Invalid order format. Expected: id;date;productIds");
        }

        int id = Integer.parseInt(tokens[0].trim());
        LocalDate date = LocalDate.parse(tokens[1].trim());

        Order order = new Order(id);
        order.setDate(date);

        // If there are product IDs
        if (tokens.length >= 3 && !tokens[2].trim().isEmpty()) {
            String[] productIds = tokens[2].split(",");

            for (String pidStr : productIds) {
                try {
                    int pid = Integer.parseInt(pidStr.trim());
                    Product p = productRepo.findById(pid);

                    if (p != null) {
                        order.addProduct(p);
                    }
                } catch (NumberFormatException ignored) {
                    // skip invalid IDs
                }
            }
        }

        return order;
    }

    @Override
    public String toLine(Order order) {
        StringBuilder sb = new StringBuilder();

        sb.append(order.getId()).append(";");
        sb.append(order.getDate()).append(";");

        var products = order.getProducts();
        for (int i = 0; i < products.size(); i++) {
            sb.append(products.get(i).getId());
            if (i < products.size() - 1) {
                sb.append(",");
            }
        }

        return sb.toString();
    }
}
