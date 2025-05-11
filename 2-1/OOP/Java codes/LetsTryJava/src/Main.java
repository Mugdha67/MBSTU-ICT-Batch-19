public class Main {
    public static void main(String[] args) {
        int n = 2; // Change this to the desired index
        long sum = fibonacciSum(n);
        System.out.println("Sum of Fibonacci series up to index " + n + " is: " + sum);
    }
    
    public static long fibonacciSum(int n) {
        if (n <= 0) {
            return 0;
        }
        
        long[] fib = new long[n + 1];
        fib[0] = 0;
        fib[1] = 1;
        
        long sum = fib[0] + fib[1];
        
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
            sum += fib[i];
        }
        
        return sum;
    }
}