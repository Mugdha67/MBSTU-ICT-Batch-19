import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DBConnection {

    protected Connection connection;
    protected PreparedStatement ps;
    protected ResultSet rs;

    public DBConnection() {
        try {
            //Class.forName("oracle.jdbc.driver.OracleDriver");
            //Class.forName("com.mysql.jdbc.Driver");
            Class.forName("com.mysql.cj.jdbc.Driver");
            //System.out.println("11111111111111");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public Connection getConnection() {
        //String url="jdbc:oracle:thin:@192.168.8.1:1521:liu";
        String url="jdbc:mysql://localhost:3306/servlet";
        try {

            connection = DriverManager.getConnection(url,"Mugdha67","1610978486");
            //connection = DriverManager.getConnection(url,"scott","tiger");
            //System.out.println(connection);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }

    public void closeAll() {
        try {
            if (this.rs != null) {
                this.rs.close();
            }
            if (this.ps != null) {
                this.ps.close();
            }
            if (this.connection != null) {
                this.connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

