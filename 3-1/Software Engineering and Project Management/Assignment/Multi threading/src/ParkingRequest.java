public class ParkingRequest {
    private final int carId;

    public ParkingRequest(int carId) {
        this.carId = carId;
    }

    public int getCarId() {
        return carId;
    }
}
