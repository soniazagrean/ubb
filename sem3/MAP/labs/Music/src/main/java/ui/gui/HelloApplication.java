package ui.gui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import service.MusicService;

import java.io.IOException;

public class HelloApplication extends Application {

    private static MusicService service;

    public static void setService(MusicService ms) {
        service = ms;
    }

    public static MusicService getService() {
        return service;
    }

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("/hello-view.fxml"));

        Scene scene = new Scene(fxmlLoader.load(), 800, 600);
        stage.setTitle("Music Distribution");
        stage.setScene(scene);
        stage.show();
    }
}
