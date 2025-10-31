package Application.controllers.DiskScheduling;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import static java.lang.Math.*;

public class diskSSTFController {
    private Stage stage;
    private Scene scene;
    private Parent root;
    public void BackToHome(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/MainUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }


    public void backToDiskScheduling(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/DiskSchedulingUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    private TextField qinput;
    @FXML
    private TextField pointerInput;
    @FXML
    private Label outputLabel;
    Vector<Integer> queueArray = new Vector<Integer>();
    public void submitInput(ActionEvent actionEvent) {
        String headPointer = pointerInput.getText();
        String queue = qinput.getText();
        if(headPointer.isEmpty()){
            outputLabel.setText("Invalid Input: Pointer is empty!");
            return;
        }
        else if(queue.isEmpty()){
            outputLabel.setText("Invalid Input: queue is empty!");
            return;
        }

        int pointer = Integer.parseInt(headPointer);
        String[] tokenQueue = queue.split(" ");
        for(String token: tokenQueue){
            queueArray.add(Integer.parseInt(token));
        }
        queueArray.add( pointer);

        int seekDistance =0;

        while (!queueArray.isEmpty()) {

            int minDistance = Integer.MAX_VALUE;
            int closestIndex = -1;

            for (int i = 0; i < queueArray.size(); i++) {
                int distance = Math.abs(queueArray.get(i) - pointer);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }

            pointer = queueArray.get(closestIndex);
            seekDistance += minDistance;

            queueArray.remove(closestIndex);
        }

        outputLabel.setText(String.valueOf(seekDistance));
        queueArray.clear();

    }
}
