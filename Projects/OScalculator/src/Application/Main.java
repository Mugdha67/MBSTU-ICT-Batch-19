package Application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage)  {
        try{
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Application/resources/MainUi.fxml"));
            primaryStage.setScene(new Scene(loader.load()));
            primaryStage.setTitle("Operating System Calculator");
            primaryStage.show();
        }catch(Exception e){
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        launch(args);
    }
}