import java.util.*;

class problem
{
    public static void main(String[] args) {
        double C,F;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the value of Celcius scale to convert into Farenheit scale: ");
        C = scanner.nextDouble();
        F = ((C*1.8))+32;
        System.out.println(F);
        
    }
}