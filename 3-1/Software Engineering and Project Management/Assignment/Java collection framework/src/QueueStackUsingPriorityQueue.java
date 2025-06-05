import java.util.*;

public class QueueStackUsingPriorityQueue {

    // Stack using PriorityQueue
    static class StackUsingPQ {
        private PriorityQueue<Element> stack;
        private int index = 0;

        public StackUsingPQ() {
            stack = new PriorityQueue<>((a, b) -> b.index - a.index);
        }

        public void push(int value) {
            stack.offer(new Element(value, index++));
        }

        public int pop() {
            return stack.poll().value;
        }

        static class Element {
            int value, index;
            Element(int value, int index) {
                this.value = value;
                this.index = index;
            }
        }
    }

    // Queue using PriorityQueue
    static class QueueUsingPQ {
        private PriorityQueue<Element> queue;
        private int index = 0;

        public QueueUsingPQ() {
            queue = new PriorityQueue<>(Comparator.comparingInt(a -> a.index));
        }

        public void offer(int value) {
            queue.offer(new Element(value, index++));
        }

        public int poll() {
            return queue.poll().value;
        }

        static class Element {
            int value, index;
            Element(int value, int index) {
                this.value = value;
                this.index = index;
            }
        }
    }

    public static void main(String[] args) {
        StackUsingPQ stack = new StackUsingPQ();
        stack.push(10);
        stack.push(20);
        System.out.println("Stack pop: " + stack.pop());

        QueueUsingPQ queue = new QueueUsingPQ();
        queue.offer(10);
        queue.offer(20);
        System.out.println("Queue poll: " + queue.poll());
    }
}
