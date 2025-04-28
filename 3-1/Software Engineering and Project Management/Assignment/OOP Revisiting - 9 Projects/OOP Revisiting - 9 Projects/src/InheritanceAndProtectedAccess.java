class gari {
    protected String type = "Vehicle";

    void show() {
        System.out.println("This is a vehicle.");
    }
}

class Bike extends gari {
    void ride() {
        System.out.println(type + " is riding on the road!");
    }
}

public class InheritanceAndProtectedAccess {
    public static void main(String[] args) {
        Bike b = new Bike();
        b.show();
        b.ride();
    }
}
