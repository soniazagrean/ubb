package ui.gui;

import domain.Order;
import domain.Product;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import service.OrderService;
import service.ProductService;
import utils.IdGenerator;

import java.time.LocalDate;
import java.util.stream.Collectors;

public class HelloController {

    private ProductService productService;
    private OrderService orderService;

    private final IdGenerator prodIdGen = new IdGenerator("last_product_id.txt");
    private final IdGenerator orderIdGen = new IdGenerator("last_order_id.txt");

    @FXML
    private TableView<Product> productTable;
    @FXML
    private TableColumn<Product, Integer> colProdId;
    @FXML
    private TableColumn<Product, String> colProdCat;
    @FXML
    private TableColumn<Product, String> colProdName;
    @FXML
    private TableColumn<Product, Double> colProdPrice;

    @FXML
    private TextField categoryFilterField;
    @FXML
    private TextField txtProdName;
    @FXML
    private TextField txtProdCat;
    @FXML
    private TextField txtProdPrice;

    @FXML
    private TableView<Order> orderTable;
    @FXML
    private TableColumn<Order, Integer> colOrderId;
    @FXML
    private TableColumn<Order, LocalDate> colOrderDate;
    @FXML
    private TableColumn<Order, Integer> colOrderItems;
    @FXML
    private TableColumn<Order, Double> colOrderTotal;

    @FXML
    private DatePicker datePickerOrder;
    @FXML
    private ListView<Product> productSelectionList;

    @FXML
    private ListView<String> reportCategoryList;
    @FXML
    private ListView<String> reportMonthlyList;
    @FXML
    private ListView<String> reportRevenueList;

    private final ObservableList<Product> productModel = FXCollections.observableArrayList();
    private final ObservableList<Order> orderModel = FXCollections.observableArrayList();

    @FXML
    public void initialize() {
        this.productService = HelloApplication.getProductService();
        this.orderService = HelloApplication.getOrderService();

        setupProductTable();
        setupOrderTable();

        refreshAll();

        productTable.getSelectionModel().selectedItemProperty().addListener((obs, oldVal, newVal) -> {
            if (newVal != null) {
                txtProdName.setText(newVal.getName());
                txtProdCat.setText(newVal.getCategory());
                txtProdPrice.setText(String.valueOf(newVal.getPrice()));
            }
        });

        orderTable.getSelectionModel().selectedItemProperty().addListener((obs, oldVal, newVal) -> {
            if (newVal != null) {
                datePickerOrder.setValue(newVal.getDate());

                productSelectionList.getSelectionModel().clearSelection();

                for (Product pInOrder : newVal.getProducts()) {
                    for (Product pInList : productSelectionList.getItems()) {
                        if (pInList.getId() == pInOrder.getId()) {
                            productSelectionList.getSelectionModel().select(pInList);
                            break;
                        }
                    }
                }
            }
        });
    }

    private void setupProductTable() {
        colProdId.setCellValueFactory(data -> new SimpleIntegerProperty(data.getValue().getId()).asObject());
        colProdCat.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getCategory()));
        colProdName.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getName()));
        colProdPrice.setCellValueFactory(data -> new SimpleDoubleProperty(data.getValue().getPrice()).asObject());

        productTable.setItems(productModel);
    }

    private void setupOrderTable() {
        colOrderId.setCellValueFactory(data -> new SimpleIntegerProperty(data.getValue().getId()).asObject());
        colOrderDate.setCellValueFactory(data -> new SimpleObjectProperty<>(data.getValue().getDate()));

        colOrderItems.setCellValueFactory(data -> new SimpleIntegerProperty(data.getValue().getProducts().size()).asObject());

        colOrderTotal.setCellValueFactory(data -> {
            double sum = data.getValue().getProducts().stream().mapToDouble(Product::getPrice).sum();
            return new SimpleDoubleProperty(sum).asObject();
        });

        orderTable.setItems(orderModel);

        productSelectionList.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
        productSelectionList.setItems(productModel);
    }

    private void refreshAll() {
        if (productService == null || orderService == null) return;

        productModel.setAll(productService.getAllProducts());
        orderModel.setAll(orderService.getAllOrders());
        loadReports();
    }

    @FXML
    protected void onAddProduct() {
        try {
            String name = txtProdName.getText();
            String cat = txtProdCat.getText();
            String priceText = txtProdPrice.getText();

            if (name == null || name.trim().isEmpty() || cat == null || priceText == null) {
                showAlert("Error", "All fields are required.");
                return;
            }

            int price = Integer.parseInt(priceText.trim());
            int id = prodIdGen.peekNext();

            Product p = new Product(id, cat, name, price);
            productService.addProduct(p);
            prodIdGen.consumeNext();

            refreshAll();
            onClearProductForm();
            showAlert("Success", "Product added successfully!");

        } catch (NumberFormatException e) {
            showAlert("Error", "Price must be a valid number.");
        } catch (Exception e) {
            showAlert("Error", "Could not add product: " + e.getMessage());
        }
    }

    @FXML
    protected void onUpdateProduct() {
        Product selected = productTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Warning", "Please select a product from the table to update.");
            return;
        }

        try {
            String name = txtProdName.getText();
            String cat = txtProdCat.getText();
            String priceText = txtProdPrice.getText();

            if (!name.isEmpty()) selected.setName(name);
            if (!cat.isEmpty()) selected.setCategory(cat);
            if (!priceText.isEmpty()) selected.setPrice(Integer.parseInt(priceText));

            productService.updateProduct(selected);
            refreshAll();
            showAlert("Success", "Product updated!");

        } catch (NumberFormatException e) {
            showAlert("Error", "Price must be a number.");
        } catch (Exception e) {
            showAlert("Error", "Update failed: " + e.getMessage());
        }
    }

    @FXML
    protected void onDeleteProduct() {
        Product selected = productTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Warning", "Please select a product to delete.");
            return;
        }

        try {
            productService.deleteProduct(selected.getId());
            refreshAll();
            onClearProductForm();
        } catch (Exception e) {
            showAlert("Error", "Delete failed: " + e.getMessage());
        }
    }

    @FXML
    protected void onFilterProducts() {
        String filter = categoryFilterField.getText();
        if (filter == null || filter.trim().isEmpty()) {
            refreshAll();
            return;
        }
        String lowerFilter = filter.toLowerCase().trim();
        var filtered = productService.getAllProducts().stream()
                .filter(p -> p.getCategory().toLowerCase().contains(lowerFilter))
                .collect(Collectors.toList());
        productModel.setAll(filtered);
    }

    @FXML
    protected void onResetProducts() {
        categoryFilterField.clear();
        refreshAll();
    }

    @FXML
    protected void onClearProductForm() {
        txtProdName.clear();
        txtProdCat.clear();
        txtProdPrice.clear();
        productTable.getSelectionModel().clearSelection();
    }

    @FXML
    protected void onAddOrder() {
        try {
            LocalDate date = datePickerOrder.getValue();
            var selectedProducts = productSelectionList.getSelectionModel().getSelectedItems();

            if (date == null) {
                showAlert("Error", "Please pick a date.");
                return;
            }
            if (selectedProducts.isEmpty()) {
                showAlert("Error", "Please select at least one product (Hold Ctrl/Cmd).");
                return;
            }

            int id = orderIdGen.peekNext();
            Order order = new Order(id);
            order.setDate(date);
            selectedProducts.forEach(order::addProduct);

            orderService.addOrder(order);
            orderIdGen.consumeNext();

            refreshAll();
            onClearOrderForm();
            showAlert("Success", "Order added successfully!");

        } catch (Exception e) {
            showAlert("Error", "Could not add order: " + e.getMessage());
        }
    }

    @FXML
    protected void onUpdateOrder() {
        Order selected = orderTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Warning", "Please select an order to update.");
            return;
        }

        try {
            LocalDate date = datePickerOrder.getValue();
            var selectedProducts = productSelectionList.getSelectionModel().getSelectedItems();

            if (date == null) throw new IllegalArgumentException("Date cannot be empty.");
            if (selectedProducts.isEmpty()) throw new IllegalArgumentException("Order must have at least one product.");

            selected.setDate(date);

            selected.getProducts().clear();
            selectedProducts.forEach(selected::addProduct);

            orderService.updateOrder(selected);
            refreshAll();
            showAlert("Success", "Order updated!");

        } catch (Exception e) {
            showAlert("Error", "Update failed: " + e.getMessage());
        }
    }

    @FXML
    protected void onDeleteOrder() {
        Order selected = orderTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Warning", "Select an order to delete.");
            return;
        }
        try {
            orderService.deleteOrder(selected.getId());
            refreshAll();
            onClearOrderForm();
        } catch (Exception e) {
            showAlert("Error", "Delete failed: " + e.getMessage());
        }
    }

    @FXML
    protected void onClearOrderForm() {
        datePickerOrder.setValue(null);
        productSelectionList.getSelectionModel().clearSelection();
        orderTable.getSelectionModel().clearSelection();
    }

    private void loadReports() {
        ObservableList<String> catData = FXCollections.observableArrayList();
        orderService.getProductCountByCategory().forEach(e ->
                catData.add(e.getKey() + ": " + e.getValue() + " orders")
        );
        reportCategoryList.setItems(catData);

        ObservableList<String> monthData = FXCollections.observableArrayList();
        orderService.getMonthlyStats().entrySet().stream()
                .sorted((e1, e2) -> Double.compare(e2.getValue().totalRevenue, e1.getValue().totalRevenue))
                .forEach(e -> monthData.add(
                        String.format("%s | %d Orders | $%.2f", e.getKey(), e.getValue().orderCount, e.getValue().totalRevenue)
                ));
        reportMonthlyList.setItems(monthData);

        ObservableList<String> revData = FXCollections.observableArrayList();
        orderService.getProductsByRevenue().forEach(e ->
                revData.add(e.getKey() + " - $" + e.getValue())
        );
        reportRevenueList.setItems(revData);
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}