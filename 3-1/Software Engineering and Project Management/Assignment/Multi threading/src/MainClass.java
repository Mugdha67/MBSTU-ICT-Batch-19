import java.util.Scanner;

public class MainClass {
    public static void main(String[] args) {
        ParkingPool pool = new ParkingPool();

        // Start parking agents (threads)
        new ParkingAgent("Agent-1", pool).start();
        new ParkingAgent("Agent-2", pool).start();
        new ParkingAgent("Agent-3", pool).start();

        Scanner scanner = new Scanner(System.in);
        int carId = 1;

        System.out.println("Press Enter to simulate car arrival, or type 'exit' to quit.");

        while (true) {
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("exit")) break;

            ParkingRequest request = new ParkingRequest(carId++);
            pool.addRequest(request);
            System.out.println("Car " + request.getCarId() + " added to parking queue.");
        }

        scanner.close();
        System.out.println("Simulation ended.");
        System.exit(0);
    }
}
