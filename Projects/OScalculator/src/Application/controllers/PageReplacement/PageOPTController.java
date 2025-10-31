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
import java.util.*;

public class PageOPTController {
    private Stage stage;
    private Scene scene;
    private Parent root;

    public void goToBack(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/PageReplacementUi.fxml"));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    public void goToHome(ActionEvent event) throws IOException {
        root = FXMLLoader.load(getClass().getResource("/Application/resources/MainUi.fxml"));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
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


    public void submitButton(ActionEvent event) {
        try {
            String framesStr = frameInput.getText().trim().replaceAll("\\s+", " ");
            String references = pagerefInput.getText().trim().replaceAll("\\s+", " ");

            if (framesStr.isEmpty() || references.isEmpty()) {
                output.setText("Invalid input: Frames or references are empty!");
                return;
            }

            int frameNumber = Integer.parseInt(framesStr);
            String[] tokenReferences = references.split(" ");
            List<Integer> pageRefArray = new ArrayList<>();

            for (String token : tokenReferences) {
                pageRefArray.add(Integer.parseInt(token));
            }

            Set<Integer> frameSet = new LinkedHashSet<>();
            int hitCount = 0;

            for (int i = 0; i < pageRefArray.size(); i++) {
                int page = pageRefArray.get(i);

                if (frameSet.contains(page)) { // Hit
                    hitCount++;
                } else {
                    if (frameSet.size() < frameNumber) {
                        frameSet.add(page);
                    } else {
                        int pageToReplace = findOptimalPage(frameSet, pageRefArray, i + 1);
                        frameSet.remove(pageToReplace);
                        frameSet.add(page);
                    }
                }
            }

            output.setText(String.valueOf(hitCount));
            miss.setText(String.valueOf(pageRefArray.size()-hitCount));
            ratio.setText(String.valueOf((double) hitCount/(double)pageRefArray.size()));


        } catch (Exception e) {
            output.setText("Error: " + e.getMessage());
        }
    }

    private int findOptimalPage(Set<Integer> frameSet, List<Integer> pages, int startIndex) {
        int farthestIndex = -1;
        int pageToReplace = -1;

        for (int framePage : frameSet) {
            int nextIndex = pages.subList(startIndex, pages.size()).indexOf(framePage);
            if (nextIndex == -1) {
                return framePage;
            }
            nextIndex += startIndex;
            if (nextIndex > farthestIndex) {
                farthestIndex = nextIndex;
                pageToReplace = framePage;
            }
        }
        return pageToReplace;
    }
}
