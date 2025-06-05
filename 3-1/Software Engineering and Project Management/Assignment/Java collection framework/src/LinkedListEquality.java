import java.util.LinkedList;

public class LinkedListEquality {
    // Compares two linked lists
    public static boolean areEqual(LinkedList<Integer> list1, LinkedList<Integer> list2) {
        return list1.equals(list2);
    }

    public static void main(String[] args) {
        LinkedList<Integer> l1 = new LinkedList<>();
        LinkedList<Integer> l2 = new LinkedList<>();

        l1.add(1); l1.add(2); l1.add(3);
        l2.add(1); l2.add(2); l2.add(3);

        System.out.println("Are linked lists equal? " + areEqual(l1, l2));
    }
}
