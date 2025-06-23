import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by User PC on 6/9/16.
 */
public class ServiceClass extends MyDBClass{

    public boolean InsetDB(String name ) {
        this.getConnection();

        String sql = "INSERT INTO STUDENT(NAME) VALUES(?)";

        try
        {
            ps = connection.prepareStatement(sql);
            ps.setString(1, name);
            //rs = ps.executeQuery();
            ps.executeUpdate();

            ps.close();
            //rs.close();
            connection.close();
            return true;
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
        return false;
    }


    public List<Student> ReadFromDB() {
        List<Student> list = new ArrayList<Student>();
        Student std = null;
        this.getConnection();
        String sql ="select * from student";
        try
        {
            ps = connection.prepareStatement(sql);
            rs = ps.executeQuery();
            while (rs.next())
            {
                std = new Student();
                std.setId(rs.getInt(1));
                std.setName(rs.getString(2));
                list.add(std);
            }
            ps.close();
            rs.close();
            connection.close();
            return list;
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
        return null;
    }

    public void UpdateStudent(int studentSerial, String newname) {

        this.getConnection();
        String sql = "update student set name=? where id=?";

        try
        {
            ps = connection.prepareStatement(sql);
            ps.setString(1, newname);
            ps.setInt(2, studentSerial);
            ps.executeUpdate();
            ps.close();
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
    }

    public void deleteStudent(int studentSerial) {
        this.getConnection();
        String sql ="delete from student where id=?";

        try
        {
            ps = connection.prepareStatement(sql);
            ps.setInt(1,studentSerial);
            ps.executeUpdate();
            ps.close();
            connection.close();

        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
    }
}