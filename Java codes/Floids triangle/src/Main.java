public class Main {
    public static void main(String[] args) {
        int n = 5; // Number of rows
        int number = 1; // Starting number

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(number + " ");
                number++; // Increment the number
            }
            System.out.println(); // Move to the next line after each row
        }
    }
}
