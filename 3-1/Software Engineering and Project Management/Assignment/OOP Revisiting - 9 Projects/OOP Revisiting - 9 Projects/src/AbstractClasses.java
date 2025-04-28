abstract class Instrument {
    abstract void playSound();

    void tune() {
        System.out.println("Tuning the instrument...");
    }
}

class Guitar extends Instrument {
    void playSound() {
        System.out.println("Strum Strum");
    }
}

public class AbstractClasses {
    public static void main(String[] args) {
        Guitar g = new Guitar();
        g.playSound();
        g.tune();
    }
}
