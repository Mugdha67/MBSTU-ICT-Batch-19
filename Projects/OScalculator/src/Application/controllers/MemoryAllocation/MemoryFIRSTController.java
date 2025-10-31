package Application.controllers.MemoryAllocation;

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
import java.util.Vector;

public class MemoryFIRSTController {
    private Stage stage;
    private Scene scene;
    private Parent root;
    public void switchToHome(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/MainUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }


    public void switchToBack(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/MemoryAllocationUi.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private TextField segmentsInput;
    @FXML
    private TextField processInput;
    @FXML
    private Label output;

    Vector<Integer> segmentArray = new Vector<Integer>();
    Vector<Integer> processArray = new Vector<Integer>();


    public void submitButton(ActionEvent actionEvent) {
        String segments = segmentsInput.getText();
        String process = processInput.getText();
        if (segments.isEmpty()) {
            output.setText("Invalid Input: Segments size is empty!");
            return;
        } else if (process.isEmpty()) {
            output.setText("Invalid Input: Process is empty!");
            return;
        }

        String[] tokenSegments = segments.split(" ");
        String[] tokenProcess = process.split(" ");
        for (String token : tokenSegments) {
            segmentArray.add(Integer.parseInt(token));
        }
        for (String token : tokenProcess) {
            processArray.add(Integer.parseInt(token));
        }

        int fragmentation = 0;
        for(int i = 0; i < processArray.size(); i++) {
            int current = processArray.get(i);
            for(int j = 0; j < segmentArray.size(); j++) {
                if(segmentArray.get(j) >= current){
                    fragmentation+=(segmentArray.get(j) - current);
                    segmentArray.remove(j);
                    break;
                }
            }
        }
        for(int i = 0; i <segmentArray.size(); i++){
            fragmentation+=segmentArray.get(i);
        }

        output.setText(String.valueOf(fragmentation));

    }
}
