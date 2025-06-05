import java.util.*;

public class KthSmallestElement {
    // Finds the kth smallest element in an ArrayList
    public static int findKthSmallest(List<Integer> list, int k) {
        Collections.sort(list); // Sorts the list in ascending order
        return list.get(k - 1); // Returns the (k-1)th element (0-indexed)
    }

    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(7, 10, 4, 3, 20, 15);
        int k = 3;
        System.out.println("Kth smallest element is: " + findKthSmallest(numbers, k));
    }
}
