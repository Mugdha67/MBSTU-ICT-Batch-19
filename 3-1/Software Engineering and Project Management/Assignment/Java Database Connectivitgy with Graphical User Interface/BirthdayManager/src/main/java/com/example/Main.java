import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class Main extends Application {
    public void start(Stage stage) {
        Label label = new Label("জন্মদিন অ্যাপ চলছে!");
        stage.setScene(new Scene(label, 300, 200));
        stage.setTitle("Bangla Birthday App");
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
