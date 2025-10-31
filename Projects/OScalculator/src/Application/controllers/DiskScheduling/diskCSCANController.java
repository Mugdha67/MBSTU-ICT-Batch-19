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
import java.util.Vector;

import static java.lang.Math.*;
import static java.util.Collections.max;

public class diskCSCANController {

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
    private Label output;
    Vector<Integer> queueArray = new Vector<Integer>();

    public void submitInput(ActionEvent actionEvent) {
        String headPointer = pointerInput.getText();
        String queue = qinput.getText();
        if (headPointer.isEmpty()) {
            output.setText("Invalid Input: Pointer is empty!");
            return;
        } else if (queue.isEmpty()) {
            output.setText("Invalid Input: queue is empty!");
            return;
        }

        int pointer = Integer.parseInt(headPointer);
        String[] tokenQueue = queue.split(" ");
        for (String token : tokenQueue) {
            queueArray.add(Integer.parseInt(token));
        }
        queueArray.add(pointer);

        int max = max(queueArray);
        double power = ceil(log(max)/log(2));
        double maxVal = pow(2, power);
        int last = (int) maxVal;

        if(!queueArray.contains(last-1)){
            queueArray.add(last-1);
        }


        Collections.sort(queueArray);

        int startIndex = 0;
        for (int i = 0; i < queueArray.size(); i++){
            if(queueArray.get(i) == pointer){
                startIndex = i;
                break;
            }
        }

        int seekDistance = 0;

        //scan right side
        seekDistance+=((last-1) - queueArray.get(startIndex));

        // scan left side
        seekDistance+=(queueArray.get(startIndex-1));

        // add the reverse from end
        seekDistance+= (last - 1);

        output.setText(String.valueOf(seekDistance));
        queueArray.clear();
    }

}
