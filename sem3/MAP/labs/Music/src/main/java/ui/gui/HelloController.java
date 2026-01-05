package ui.gui;

import domain.Music;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import service.MusicService;
import java.util.*;

public class HelloController {
    private MusicService service;

    @FXML
    private TableView<Music> musicTable;
    @FXML
    private TableColumn<Music, Integer> colId;
    @FXML
    private TableColumn<Music, String> colBand;
    @FXML
    private TableColumn<Music, String> colTitle;
    @FXML
    private TableColumn<Music, String> colGenre;
    @FXML
    private TableColumn<Music, String> colTime;

    @FXML
    private ComboBox<String> genreComboBox;
    @FXML
    private TextField playlistNameField;

    private final ObservableList<Music> musicModel = FXCollections.observableArrayList();

    @FXML
    public void initialize() {
        this.service = HelloApplication.getService();
        setupMusicTable();
        loadInitialData();
        setupGenreFilter();
    }

    @FXML
    private void setupGenreFilter() {
        genreComboBox.getSelectionModel().selectedItemProperty().addListener((obs, oldVal, newVal) -> {
            if (newVal != null) {
                musicModel.setAll(service.filterByGenre(newVal));
            }
        });
    }

    @FXML
    private void onReset() {
        genreComboBox.getSelectionModel().clearSelection();
        musicModel.setAll(service.getSortedMusic());
    }

    @FXML
    private void onGeneratePlaylist() {
        String name = playlistNameField.getText();
        if (name == null || name.trim().isEmpty()) {
            showAlert("Error", "Add another name for the playlist");
            return;
        }

        try {
            showAlert("Success", "Playlist '" + name + "' generated");
        } catch (Exception e) {
            showAlert("Error", e.getMessage());
        }
    }

    private void setupMusicTable() {
        colId.setCellValueFactory(new PropertyValueFactory<>("id"));
        colBand.setCellValueFactory(new PropertyValueFactory<>("band"));
        colTitle.setCellValueFactory(new PropertyValueFactory<>("title"));
        colGenre.setCellValueFactory(new PropertyValueFactory<>("genre"));
        colTime.setCellValueFactory(new PropertyValueFactory<>("time"));
        musicTable.setItems(musicModel);
    }

    private void loadInitialData() {
        musicModel.setAll(service.getSortedMusic());

        genreComboBox.setItems(FXCollections.observableArrayList(service.getUniqueGenres()));
    }

    private void showAlert(String title, String content) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(content);
        alert.showAndWait();
    }
}
