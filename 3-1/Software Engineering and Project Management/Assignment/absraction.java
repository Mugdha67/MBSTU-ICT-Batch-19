import java.io.PrintStream;

interface Machine {
    PrintStream o = System.out;
    void initialEngine();
    void finalEngine();
}

abstract class Transport {
    String trademark;
    int manufYear;
    int engineCapacity;

    public Transport(String trademark, int manufYear, int engineCapacity) {
        this.trademark = trademark;
        this.manufYear = manufYear;
        this.engineCapacity = engineCapacity;
    }

    abstract void propel();

    public void exhibitInfo() {
        Machine.o.println("Trademark: " + trademark + ", Manufacture Year: " + manufYear + ", Engine Capacity: " + engineCapacity);
    }
}

class Car extends Transport implements Machine {

    public Car(String trademark, int manufYear, int engineCapacity) {
        super(trademark, manufYear, engineCapacity);
    }

    @Override
    public void initialEngine() {
        o.println("Car engine is starting...");
    }

    @Override
    public void finalEngine() {
        o.println("Car engine is ending...");
    }

    @Override
    public void propel() {
        o.println("Car is being driven...");
    }
}

class Bike extends Transport implements Machine {

    public Bike(String trademark, int manufYear, int engineCapacity) {
        super(trademark, manufYear, engineCapacity);
    }

    @Override
    public void initialEngine() {
        o.println("Bike engine is starting...");
    }

    @Override
    public void finalEngine() {
        o.println("Bike engine is ending...");
    }

    @Override
    public void propel() {
        o.println("Bike is being rode...");
    }
}

class Boat extends Transport implements Machine {

    public Boat(String trademark, int manufYear, int engineCapacity) {
        super(trademark, manufYear, engineCapacity);
    }

    @Override
    public void initialEngine() {
        o.println("Boat engine is starting...");
    }

    @Override
    public void finalEngine() {
        o.println("Boat engine is ending...");
    }

    @Override
    public void propel() {
        o.println("Boat is being sailed...");
    }
}

public class Abstraction {

    public static void main(String[] args) {

        Machine.o.println("I am Md. Atif Rahman Rudro. My ID is IT:22002");
        Machine.o.println();

        Transport car = new Car("X-Corolla", 2002, 1800);
        car.exhibitInfo();
        ((Machine) car).initialEngine();
        car.propel();
        ((Machine) car).finalEngine();
        Machine.o.println();

        Transport bike = new Bike("Hero-Honda", 2001, 150);
        bike.exhibitInfo();
        ((Machine) bike).initialEngine();
        bike.propel();
        ((Machine) bike).finalEngine();
        Machine.o.println();

        Transport boat = new Boat("Osprey", 2002, 1500);
        boat.exhibitInfo();
        ((Machine) boat).initialEngine();
        boat.propel();
        ((Machine) boat).finalEngine();
    }
}
