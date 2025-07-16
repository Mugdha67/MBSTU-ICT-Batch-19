import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

@WebServlet("/TestServlet")
public class TestServlet extends HttpServlet {

    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String name = request.getParameter("studentName");
        String email = request.getParameter("studentEmail");
        String action = request.getParameter("action");

        ServiceClass service = new ServiceClass();
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // Start HTML with custom CSS styling
        out.println("<html><head><meta charset='UTF-8'><title>Student Servlet</title>");
        out.println("<style>");
        out.println("body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #f4f6f8; margin: 0; padding: 20px; }");
        out.println(".container { max-width: 800px; margin: auto; background: #fff; padding: 20px 30px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); border-radius: 10px; }");
        out.println("h2 { text-align: center; color: #2c3e50; }");
        out.println("p { font-size: 16px; color: #34495e; }");
        out.println("table { border-collapse: collapse; width: 100%; margin-top: 20px; }");
        out.println("th, td { border: 1px solid #ddd; padding: 12px; text-align: left; }");
        out.println("th { background-color: #2ecc71; color: white; }");
        out.println("tr:nth-child(even) { background-color: #f9f9f9; }");
        out.println("tr:hover { background-color: #f1f1f1; }");
        out.println(".status { padding: 10px; margin-top: 15px; border-radius: 5px; }");
        out.println(".success { background-color: #d4edda; color: #155724; border: 1px solid #c3e6cb; }");
        out.println(".fail { background-color: #f8d7da; color: #721c24; border: 1px solid #f5c6cb; }");
        out.println(".footer { text-align: center; margin-top: 50px; font-size: 14px; color: #888; }");
        out.println("</style></head><body>");
        out.println("<div class='container'>");

        // Title
        out.println("<h2>Student Management - Action: " + action + "</h2>");

        switch (action) {
            case "Insert":
                if (service.insertDB(name, email)) {
                    out.println("<div class='status success'>Inserted successfully.</div>");
                } else {
                    out.println("<div class='status fail'>Insertion failed.</div>");
                }
                break;

            case "View":
                List<String> students = service.viewDB();
                if (students.isEmpty()) {
                    out.println("<div class='status fail'>No students found.</div>");
                } else {
                    out.println("<table>");
                    out.println("<tr><th>Name</th><th>Email</th></tr>");
                    for (String student : students) {
                        String[] parts = student.split(", Email: ");
                        String studentName = parts[0].replace("Name: ", "");
                        String studentEmail = parts.length > 1 ? parts[1] : "";
                        out.println("<tr><td>" + studentName + "</td><td>" + studentEmail + "</td></tr>");
                    }
                    out.println("</table>");
                }
                break;

            case "Update":
                if (service.updateDB(name, email)) {
                    out.println("<div class='status success'>Updated successfully.</div>");
                } else {
                    out.println("<div class='status fail'>Update failed. Name not found?</div>");
                }
                break;

            case "Delete":
                if (service.deleteDB(name)) {
                    out.println("<div class='status success'>Deleted successfully.</div>");
                } else {
                    out.println("<div class='status fail'>Delete failed. Name not found?</div>");
                }
                break;

            default:
                out.println("<div class='status fail'>Unknown action.</div>");
        }

        // Footer
        out.println("<div class='footer'>Developed by <strong>Mugdha67</strong></div>");

        // End of page
        out.println("</div></body></html>");
    }
}
