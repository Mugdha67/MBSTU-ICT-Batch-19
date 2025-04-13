package application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import javafx.stage.Stage;
import javafx.scene.Parent;

public class LoginController {
    @FXML private TextField usernameField;
    @FXML private PasswordField passwordField;
    @FXML private Label errorLabel;

    public void login(ActionEvent event) {
        String username = usernameField.getText();
        String password = passwordField.getText();
        if(username.equals("admin") && password.equals("1234")) {
            try {
                Stage stage = (Stage) usernameField.getScene().getWindow();
                Parent root = FXMLLoader.load(getClass().getResource("/dashboard.fxml"));
                stage.setScene(new Scene(root));
            } catch(Exception e) {
                e.printStackTrace();
            }
        } else {
            errorLabel.setText("Invalid credentials");
        }
    }
}
