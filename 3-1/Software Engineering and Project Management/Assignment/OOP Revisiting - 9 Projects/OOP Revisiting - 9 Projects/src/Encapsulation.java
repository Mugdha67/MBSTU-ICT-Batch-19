class WaterTank {
    private double waterLevel; // private: only accessible inside the class

    public void fill(double amount) {
        if (amount > 0) waterLevel += amount;
    }

    public double getWaterLevel() {
        return waterLevel;
    }
}

public class Encapsulation {
    public static void main(String[] args) {
        WaterTank tank = new WaterTank();
        tank.fill(150);
        System.out.println(tank.getWaterLevel());
    }
}
