import java.util.Scanner;

// Custom exception for age
class UnderAgeException extends Exception {
    public UnderAgeException(String message) {
        super(message);
    }
}

// Custom exception for department
class InvalidDepartmentException extends Exception {
    public InvalidDepartmentException(String message) {
        super(message);
    }
}

public class StudentValidator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input
        System.out.print("Enter age: ");
        int age = scanner.nextInt();
        scanner.nextLine(); // consume newline

        System.out.print("Enter department: ");
        String department = scanner.nextLine();

        boolean hasError = false;

        // Check conditions independently
        try {
            if (age < 18) {
                hasError = true;
                throw new UnderAgeException("Age must be 18 or older.");
            }
        } catch (UnderAgeException e) {
            System.out.println("Exception: " + e.getMessage());
        }

        try {
            if (!department.equalsIgnoreCase("ICT")) {
                hasError = true;
                throw new InvalidDepartmentException("Department must be ICT.");
            }
        } catch (InvalidDepartmentException e) {
            System.out.println("Exception: " + e.getMessage());
        }

        if (!hasError) {
            System.out.println("Valid");
        }

        scanner.close();
    }
}
