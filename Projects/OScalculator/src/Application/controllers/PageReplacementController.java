package Application.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class PageReplacementController {
    private Stage stage;
    private Scene scene;
    private Parent root;
    @FXML
    public void switchToFIFO(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/PageReplacementUi/PageFIFOUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToLRU(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/PageReplacementUi/PageLRUUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToOPT(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/PageReplacementUi/PageOPTUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    public void goToHome(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/MainUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
}
