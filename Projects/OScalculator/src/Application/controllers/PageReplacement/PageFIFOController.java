package Application.controllers.PageReplacement;

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

public class PageFIFOController {
    private Stage stage;
    private Scene scene;
    private Parent root;

    public void goToBack(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/PageReplacementUi.fxml"));
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

    @FXML
    private TextField frameInput;
    @FXML
    private TextField pagerefInput;
    @FXML
    private Label output;
    @FXML
    private Label miss;
    @FXML
    private Label ratio;

    Vector<Integer> pageRefArray = new Vector<Integer>();


    public void submitButton(ActionEvent event)  {
        try {
            String frames = frameInput.getText();
            String references = pagerefInput.getText();
            if (frames.isEmpty()) {
                output.setText("Invalid Input: frames size is empty!");
                return;
            } else if (references.isEmpty()) {
                output.setText("Invalid Input: references is empty!");
                return;
            }

            String[] tokenReferences = references.split(" ");

            int frameNumber = Integer.parseInt(frames);

            for (String token : tokenReferences) {
                pageRefArray.add(Integer.parseInt(token));
            }
            int hitCount = 0;

            Vector<Integer> ram = new Vector<Integer>(frameNumber);
            int lastIndex = 0;
            for (int i = 0; i < pageRefArray.size() && ram.size() < frameNumber; i++) {
                System.out.println(ram);
                lastIndex = i;
                if (ram.contains(pageRefArray.get(i))) {
                    hitCount++;
                    continue;
                }
                ram.add(pageRefArray.get(i));
            }
            int changeIndex = 0;

            for (int i = lastIndex+1; i < pageRefArray.size(); i++) {
                System.out.println(ram);
                if (ram.contains(pageRefArray.get(i))) {
                    hitCount++;
                    continue;
                } else {
                    ram.remove(changeIndex);
                    ram.add(changeIndex, pageRefArray.get(i));
                    changeIndex++;
                    if (changeIndex == frameNumber) changeIndex = 0;
                }
            }
            System.out.println(ram);

            output.setText(String.valueOf(hitCount));
            miss.setText(String.valueOf(pageRefArray.size()-hitCount));
            ratio.setText(String.valueOf((double) hitCount/(double) pageRefArray.size()));

            pageRefArray.clear();
        }catch (Exception e) {
            System.out.println(e);
        }

    }
}
