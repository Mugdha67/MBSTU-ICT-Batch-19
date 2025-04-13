package application;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class StudentFormController {
    @FXML private TextField nameField;
    @FXML private TextField ageField;
    @FXML private TextField gradeField;

    public void saveStudent() {
        String name = nameField.getText();
        int age = Integer.parseInt(ageField.getText());
        String grade = gradeField.getText();

        Student newStudent = new Student(name, age, grade);
        // This is where you'd add it to a central list or DB

        Stage stage = (Stage) nameField.getScene().getWindow();
        stage.close(); // Just close for demo purposes
    }
}
