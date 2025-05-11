public class Main {
    public static void main(String[] args) {
        int[] array = {4, 2, 7, 1, 9, 5};

        int min = array[0];
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            min = (array[i]<min)?array[i]: min;
            max = (array[i] > max) ? array[i] : max;
        }
        System.out.println("Smallest number: " + min);
        System.out.println("Largest number: " + max);
    }
}
