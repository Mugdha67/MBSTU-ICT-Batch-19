import java.util.Scanner;

public class ATM {
    private double balance = 1000.0;

    public void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
    }

    public void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient balance!");
        }
    }

    public void checkBalance() {
        System.out.println("Current Balance: " + balance);
    }

    public static void main(String[] args) {
        ATM atm = new ATM();
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            if (choice == 1) {
                System.out.print("Enter deposit amount: ");
                atm.deposit(sc.nextDouble());
            } else if (choice == 2) {
                System.out.print("Enter withdraw amount: ");
                atm.withdraw(sc.nextDouble());
            } else if (choice == 3) {
                atm.checkBalance();
            } else if (choice == 4) {
                System.out.println("Thank you for using ATM!");
            } else {
                System.out.println("Invalid choice. Try again.");
            }
        } while (choice != 4);

        sc.close();
    }
}
