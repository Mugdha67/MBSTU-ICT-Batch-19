import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ServiceClass extends MyDbClass {

    public boolean InsertDB(int id, String name) {
        this.getConnection();
        String sql = "INSERT INTO students(id, name) VALUES(?, ?)";

        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, id);
            ps.setString(2, name);
            ps.executeUpdate();

            ps.close();
            connection.close();
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    public List<Student> ReadFromDB() {
        List<Student> list = new ArrayList<>();
        this.getConnection();
        String sql = "SELECT * FROM students";

        try {
            ps = connection.prepareStatement(sql);
            rs = ps.executeQuery();

            while (rs.next()) {
                Student std = new Student();
                std.setId(rs.getInt("id"));
                std.setName(rs.getString("name"));
                list.add(std);
            }

            ps.close();
            rs.close();
            connection.close();
            return list;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    public void UpdateStudent(int studentId, String newName) {
        this.getConnection();
        String sql = "UPDATE students SET name = ? WHERE id = ?";

        try {
            ps = connection.prepareStatement(sql);
            ps.setString(1, newName);
            ps.setInt(2, studentId);
            ps.executeUpdate();

            ps.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void DeleteStudent(int studentId) {
        this.getConnection();
        String sql = "DELETE FROM students WHERE id = ?";

        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, studentId);
            ps.executeUpdate();

            ps.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
