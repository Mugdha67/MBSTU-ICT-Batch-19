// First interface
interface Animal {
    void sound();
}

// Second interface
interface vehicle {
    void speed();
}

// Class implementing both interfaces
class FlyingCar implements Animal, vehicle {
    // Implementing sound() method from Animal interface
    public void sound() {
        System.out.println("FlyingCar makes an animal-like sound.");
    }

    // Implementing speed() method from Vehicle interface
    public void speed() {
        System.out.println("FlyingCar moves at a high speed.");
    }
}

public class inheritence {
    public static void main(String[] args) {
        FlyingCar myFlyingCar = new FlyingCar();

        // Accessing methods from both interfaces
        myFlyingCar.sound();   // From Animal interface
        myFlyingCar.speed();   // From Vehicle interface
    }
}
