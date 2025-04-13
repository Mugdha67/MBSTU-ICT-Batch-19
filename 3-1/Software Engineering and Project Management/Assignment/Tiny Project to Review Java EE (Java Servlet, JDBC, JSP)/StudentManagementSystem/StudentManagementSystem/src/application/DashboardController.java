package application;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.scene.Parent;

public class DashboardController {
    @FXML private TableView<Student> studentTable;
    @FXML private TableColumn<Student, String> nameCol;
    @FXML private TableColumn<Student, Integer> ageCol;
    @FXML private TableColumn<Student, String> gradeCol;

    private ObservableList<Student> studentList = FXCollections.observableArrayList();

    public void initialize() {
        nameCol.setCellValueFactory(new PropertyValueFactory<>("name"));
        ageCol.setCellValueFactory(new PropertyValueFactory<>("age"));
        gradeCol.setCellValueFactory(new PropertyValueFactory<>("grade"));
        studentTable.setItems(studentList);
    }

    public void addStudent() {
        try {
            Stage stage = (Stage) studentTable.getScene().getWindow();
            Parent root = FXMLLoader.load(getClass().getResource("/student_form.fxml"));
            stage.setScene(new Scene(root));
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
