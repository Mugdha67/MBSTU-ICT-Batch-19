import java.util.*;

class Student {
    String name;
    int age;
    String course;

    Student(String name, int age, String course) {
        this.name = name;
        this.age = age;
        this.course = course;
    }

    public String toString() {
        return name + ", Age: " + age + ", Course: " + course;
    }
}

public class StudentTreeMap {
    public static void main(String[] args) {
        TreeMap<Integer, Student> students = new TreeMap<>();

        students.put(1001, new Student("Alice", 20, "CS"));
        students.put(1002, new Student("Bob", 21, "Math"));
        students.put(1003, new Student("Charlie", 22, "Physics"));

        students.forEach((id, student) -> System.out.println(id + ": " + student));
    }
}
