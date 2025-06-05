import java.util.LinkedList;

public class ParkingPool {
    private final LinkedList<ParkingRequest> queue = new LinkedList<>();

    // Add a request to the pool
    public synchronized void addRequest(ParkingRequest request) {
        queue.addLast(request);
        notify(); // Notify one waiting ParkingAgent
    }

    // Retrieve a request from the pool
    public synchronized ParkingRequest getRequest() throws InterruptedException {
        while (queue.isEmpty()) {
            wait(); // Wait for new requests
        }
        return queue.removeFirst();
    }
}
