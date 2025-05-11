import java.util.Scanner;
public class LargestSmallest {
    public static void main(String[] args) {
        int num1,num2,num3,num4;
        int largest, smallest;
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter 4 values : ");
        num1=scanner.nextInt();
        num2=scanner.nextInt();
        num3=scanner.nextInt();
        num4=scanner.nextInt();
        largest = (num1 > num2) ? ((num1 > num3) ? ((num1 > num4) ? num1 : num4) : ((num3 > num4) ? num3 : num4)) :
                ( (num2 > num3) ? ((num2 > num4) ? num2 : num4) : ((num3 > num4) ? num3 : num4));

        smallest = (num1 < num2) ? ((num1 < num3) ? ((num1 < num4) ? num1 : num4) : ((num3 < num4) ? num3 : num4)) :
                ((num2 < num3) ? ((num2 < num4) ? num2 : num4) : ((num3 < num4) ? num3 : num4));

        System.out.println("The largest number is: " + largest);
        System.out.println("The smallest number is: " + smallest);
        scanner.close();
    }
}
