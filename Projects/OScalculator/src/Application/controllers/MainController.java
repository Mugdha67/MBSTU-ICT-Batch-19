package Application.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class MainController {
    private  Stage stage;
    private  Scene scene;
    private Parent root;
    @FXML
    public void switchToProcessScheduing(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchTodiskScheduling(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/DiskSchedulingUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToPageReplacement(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/PageReplacementUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToMemoryAllocation(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/MemoryAllocationUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
}
