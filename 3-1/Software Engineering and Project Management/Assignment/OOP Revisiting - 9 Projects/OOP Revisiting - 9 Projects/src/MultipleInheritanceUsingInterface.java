interface Drivable {
    void drive();
}

interface Floatable {
    void floatOnWater();
}

class AmphibiousCar implements Drivable, Floatable {
    public void drive() {
        System.out.println("Amphibious Car is driving on land...");
    }

    public void floatOnWater() {
        System.out.println("Amphibious Car is floating on water...");
    }
}

public class MultipleInheritanceUsingInterface {
    public static void main(String[] args) {
        AmphibiousCar car = new AmphibiousCar();
        car.drive();
        car.floatOnWater();
    }
}
