public class ProductFactory implements Factory<Product> {

    @Override
    public Product fromTokens(String[] tokens) {
        if (tokens.length != 4) {
            throw new IllegalArgumentException("Invalid product format. Expected 4 fields.");
        }

        int id = Integer.parseInt(tokens[0].trim());
        String category = tokens[1].trim();
        String name = tokens[2].trim();
        int price = Integer.parseInt(tokens[3].trim());

        return new Product(id, category, name, price);
    }

    @Override
    public String toLine(Product product) {
        return product.getId() + ";" +
                product.getCategory() + ";" +
                product.getName() + ";" +
                product.getPrice();
    }
}