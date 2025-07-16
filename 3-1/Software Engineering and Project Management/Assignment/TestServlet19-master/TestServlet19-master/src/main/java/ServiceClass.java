import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ServiceClass extends DBConnection {

    public boolean insertDB(String name, String email) {
        this.getConnection();
        String sql = "INSERT INTO MYSTUDENT(NAME, EMAIL) VALUES(?, ?)";
        try {
            ps = connection.prepareStatement(sql);
            ps.setString(1, name);
            ps.setString(2, email);
            ps.executeUpdate();
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeAll();
        }
        return false;
    }

    public List<String> viewDB() {
        List<String> result = new ArrayList<>();
        this.getConnection();
        String sql = "SELECT NAME, EMAIL FROM MYSTUDENT";
        try {
            ps = connection.prepareStatement(sql);
            rs = ps.executeQuery();
            while (rs.next()) {
                result.add("Name: " + rs.getString("NAME") + ", Email: " + rs.getString("EMAIL"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeAll();
        }
        return result;
    }

    public boolean updateDB(String name, String email) {
        this.getConnection();
        String sql = "UPDATE MYSTUDENT SET EMAIL = ? WHERE NAME = ?";
        try {
            ps = connection.prepareStatement(sql);
            ps.setString(1, email);
            ps.setString(2, name);
            return ps.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeAll();
        }
        return false;
    }

    public boolean deleteDB(String name) {
        this.getConnection();
        String sql = "DELETE FROM MYSTUDENT WHERE NAME = ?";
        try {
            ps = connection.prepareStatement(sql);
            ps.setString(1, name);
            return ps.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeAll();
        }
        return false;
    }
}
