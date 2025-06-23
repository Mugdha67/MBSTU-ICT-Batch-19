import java.util.List;
import java.util.Scanner;

public class ConsoleInput {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ServiceClass serviceClass = new ServiceClass();

        while (true) {
            System.out.println("\n1. Insert Student");
            System.out.println("2. Show All Students");
            System.out.println("3. Update Student Name");
            System.out.println("4. Delete Student");
            System.out.println("5. Exit");
            System.out.print("Choose option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // clear newline

            if (choice == 1) {
                System.out.print("Enter ID: ");
                int id = scanner.nextInt();
                scanner.nextLine();
                System.out.print("Enter Name: ");
                String name = scanner.nextLine();
                serviceClass.InsertDB(id, name);
            } else if (choice == 2) {
                List<Student> students = serviceClass.ReadFromDB();
                if (students != null) {
                    for (Student s : students) {
                        System.out.println("ID: " + s.getId() + ", Name: " + s.getName());
                    }
                }
            } else if (choice == 3) {
                System.out.print("Enter ID to Update: ");
                int id = scanner.nextInt();
                scanner.nextLine();
                System.out.print("Enter New Name: ");
                String newName = scanner.nextLine();
                serviceClass.UpdateStudent(id, newName);
            } else if (choice == 4) {
                System.out.print("Enter ID to Delete: ");
                int id = scanner.nextInt();
                serviceClass.DeleteStudent(id);
            } else if (choice == 5) {
                System.out.println("Goodbye!");
                break;
            } else {
                System.out.println("Invalid choice.");
            }
        }
    }
}
