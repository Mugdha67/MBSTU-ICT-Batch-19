package Application.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class ProcessSchedulingController {
    private Stage stage;
    private Scene scene;
    private Parent root;
    @FXML
    public void switchToFCFS(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi/ProcessFCFSUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToPrePriority(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi/ProcessPrePriorityUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToNonPrePriority(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi/ProcessNonPrePriorityUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToPreSJF(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi/ProcessPreSJFUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToNonPreSJF(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi/ProcessNonPreSJFUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void switchToRR(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/ProcessSchedulingUi/ProcessRRUi.fxml"));
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
