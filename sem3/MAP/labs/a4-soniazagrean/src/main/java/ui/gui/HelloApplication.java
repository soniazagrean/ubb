package ui.gui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import service.OrderService;
import service.ProductService;

import java.io.IOException;

public class HelloApplication extends Application {

    private static ProductService productService;
    private static OrderService orderService;

    public static void setServices(ProductService ps, OrderService os) {
        productService = ps;
        orderService = os;
    }

    public static ProductService getProductService() {
        return productService;
    }

    public static OrderService getOrderService() {
        return orderService;
    }

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("/hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 800, 600);

        stage.setTitle("Electronics Store Management");
        stage.setScene(scene);
        stage.show();
    }
}