public class ParkingAgent extends Thread {
    private final ParkingPool pool;
    private final String agentName;

    public ParkingAgent(String name, ParkingPool pool) {
        this.agentName = name;
        this.pool = pool;
    }

    @Override
    public void run() {
        while (true) {
            try {
                ParkingRequest request = pool.getRequest();
                System.out.println(agentName + " is parking car " + request.getCarId());
                Thread.sleep(1000); // Simulate time taken to park
            } catch (InterruptedException e) {
                System.out.println(agentName + " was interrupted.");
                break;
            }
        }
    }
}
