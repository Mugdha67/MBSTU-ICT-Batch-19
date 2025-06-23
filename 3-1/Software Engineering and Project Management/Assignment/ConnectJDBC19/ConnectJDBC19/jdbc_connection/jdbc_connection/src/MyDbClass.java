import java.sql.*;

public class MyDbClass {
    protected Connection connection;
    protected PreparedStatement ps;
    protected ResultSet rs;

    public MyDbClass() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver"); // For MySQL 8.x
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public Connection getConnection() {
        String url = "jdbc:mysql://localhost:3306/student";
        try {
            connection = DriverManager.getConnection(url, "root", "052312");
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }

    public void closeAll() {
        try {
            if (rs != null) rs.close();
            if (ps != null) ps.close();
            if (connection != null) connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
