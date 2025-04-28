interface vehicle {
    void move();
}

class Car implements vehicle {
    public void move() {
        System.out.println("Car is moving...");
    }
}

public class Interface {
    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.move();
    }
}
