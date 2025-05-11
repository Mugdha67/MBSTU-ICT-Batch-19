import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        String[] strings = {"red", "green", "blue", "yellow"};

        // Correct method call to sort the array
        Arrays.sort(strings);

        System.out.println("Sorted string: ");
        for (String str : strings) {
            System.out.println(str);
        }
    }
}
