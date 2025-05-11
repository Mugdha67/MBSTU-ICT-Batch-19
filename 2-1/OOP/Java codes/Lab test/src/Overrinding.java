class Car {
    public void move() {
        System.out.println("Vehicle is moving");
    }

    public void sound() {
        System.out.println("Vehicle makes a generic sound");
    }
}

class Supra {
    private Car vehicle;

    public Supra() {
        vehicle = new Car();
    }

    public void move() {
        System.out.println("Supra moves fast");
    }

    public void sound() {
        System.out.println("Supra goes siuuuu");
    }
}

public class Overrinding {
    public static void main(String[] args) {
        Car myVehicle = new Car();
        myVehicle.move();
        myVehicle.sound();

        Supra mySupra = new Supra();
        mySupra.move();
        mySupra.sound();
    }
}
