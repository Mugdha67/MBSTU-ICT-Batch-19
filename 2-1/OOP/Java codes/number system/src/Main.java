import java.util.*;
public class Main{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int choice,number;
        String S;
        System.out.println("select conversion type: ");
        System.out.println("1. Decimal to Binary.");
        System.out.println("2. Decimal to Octal.");
        System.out.println("3. Decimal to Hexadecimal.");
        System.out.println("4. Binary to Decimal.");
        System.out.println("5. Octal to Decimal.");
        System.out.println("6. Hexadecimal to Decimal.");

        choice=sc.nextInt();
        switch(choice)
        {
            case 1:
                number=sc.nextInt();
                System.out.println(Integer.toBinaryString(number));
                break;
            case 2:
                number=sc.nextInt();
                System.out.println(Integer.toOctalString(number));
                break;
            case 3:
                number=sc.nextInt();
                System.out.println(Integer.toHexString(number).toUpperCase());
                break;
            case 4:
                S=sc.next();
                System.out.println(Integer.parseInt(S,2));
                break;
            case 5:
                 S=sc.next();
                System.out.println(Integer.parseInt(S,8));
                break;
            case 6:
                 S=sc.next();
                System.out.println(Integer.parseInt(S,16));
                break;
            default:
                System.out.println("Invalid choice.");
        }
        sc.close();
    }
}