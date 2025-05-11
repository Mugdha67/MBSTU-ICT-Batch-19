//
//class Vehicle {
//    public void move() {
//        System.out.println("Vehicle is moving");
//    }
//
//    public void sound() {
//        System.out.println("Vehicle makes a generic sound");
//    }
//}
//class Lamborghini extends Vehicle {
//    public void move() {
//        System.out.println("Lamborghini moves fast");
//    }
//    public void sound() {
//        System.out.println("Lamborghini goes siuuuu");
//    }
//}
//
//public class Overriding {
//    public static void main(String[] args) {
//        Vehicle myVehicle = new Vehicle();
//        myVehicle.move();
//        myVehicle.sound();
//
//        Lamborghini myLambo = new Lamborghini();
//        myLambo.move();
//        myLambo.sound();
//    }
//}
//
class Vehicle {
    public void move() {
        System.out.println("Vehicle is moving");
    }

    public void sound() {
        System.out.println("Vehicle makes a generic sound");
    }
}

class Lamborghini {
    private Car vehicle;

    public Lamborghini() {
        vehicle = new Car();
    }

    public void move() {
        System.out.println("Lamborghini moves fast");
    }

    public void sound() {
        System.out.println("Lamborghini goes siuuuu");
    }

    public void vehicleMove() {
        vehicle.move();  // Calls Vehicle's move method
    }

    public void vehicleSound() {
        vehicle.sound();  // Calls Vehicle's sound method
    }
}

public class Overriding {
    public static void main(String[] args) {
        Car myVehicle = new Car();
        myVehicle.move();
        myVehicle.sound();

        Supra myLambo = new Supra();
        myLambo.move();
        myLambo.sound();


    }
}
