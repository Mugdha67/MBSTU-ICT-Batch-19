import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class StudentDatabaseGUI extends JFrame {
    JTextField nameField, emailField;
    JTextArea displayArea;

    // Database credentials
    final String URL = "jdbc:mysql://localhost:3306/school"; // Make sure DB exists
    final String USER = "root";      // change as needed
    final String PASSWORD = "";      // change as needed

    public StudentDatabaseGUI() {
        setTitle("Java Database Connectivity with GUI");
        setLayout(new FlowLayout());

        add(new JLabel("Name:"));
        nameField = new JTextField(20);
        add(nameField);

        add(new JLabel("Email:"));
        emailField = new JTextField(20);
        add(emailField);

        JButton insertBtn = new JButton("Insert");
        JButton viewBtn = new JButton("View All");

        insertBtn.addActionListener(e -> insertStudent());
        viewBtn.addActionListener(e -> viewStudents());

        add(insertBtn);
        add(viewBtn);

        displayArea = new JTextArea(10, 40);
        displayArea.setEditable(false);
        add(new JScrollPane(displayArea));

        setSize(500, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    private void insertStudent() {
        try (Connection conn = getConnection()) {
            String sql = "INSERT INTO students(name, email) VALUES (?, ?)";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, nameField.getText());
            stmt.setString(2, emailField.getText());
            stmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Student inserted successfully!");
            nameField.setText("");
            emailField.setText("");
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
        }
    }

    private void viewStudents() {
        displayArea.setText("");
        try (Connection conn = getConnection()) {
            String sql = "SELECT * FROM students";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                displayArea.append("ID: " + rs.getInt("id") + ", Name: " + rs.getString("name")
                        + ", Email: " + rs.getString("email") + "\n");
            }
        } catch (SQLException ex) {
            displayArea.setText("Error: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        // Load JDBC driver
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            JOptionPane.showMessageDialog(null, "MySQL JDBC Driver not found!");
            return;
        }

        SwingUtilities.invokeLater(() -> new StudentDatabaseGUI());
    }
}
