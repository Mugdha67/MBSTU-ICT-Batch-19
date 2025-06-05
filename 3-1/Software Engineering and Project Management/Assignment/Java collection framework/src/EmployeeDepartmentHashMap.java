import java.util.HashMap;

public class EmployeeDepartmentHashMap {
    public static void main(String[] args) {
        HashMap<Integer, String> employeeDept = new HashMap<>();

        employeeDept.put(101, "HR");
        employeeDept.put(102, "Finance");
        employeeDept.put(103, "Engineering");

        employeeDept.forEach((id, dept) -> System.out.println("Employee ID: " + id + ", Department: " + dept));
    }
}
