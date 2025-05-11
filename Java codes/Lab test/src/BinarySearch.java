import java.util.*;
public class BinarySearch {

    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (array[middle] == target) {
                return middle;
            }

            if (array[middle] < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int[] array = {1,2,3,4,5,6,7,8,9,10};
        System.out.print("Enter the number to search: ");
        int target = s.nextInt();
        int result = binarySearch(array, target);
        if (result == -1) {
            System.out.println("Number not found in the array.");
        } else {
            System.out.println("Number found at index: " + result);
        }

        s.close();
    }
}
