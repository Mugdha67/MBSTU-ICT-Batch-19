class MobilePhone {
    String brand;
    int price;

    void call() {
        System.out.println("Making a call...");
    }
}

public class ClassAndObjects {
    public static void main(String[] args) {
        MobilePhone myPhone = new MobilePhone(); // object creation
        myPhone.brand = "Samsung";
        myPhone.price = 50000;
        myPhone.call();
    }
}
