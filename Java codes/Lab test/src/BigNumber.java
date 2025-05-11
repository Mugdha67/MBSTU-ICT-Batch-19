import java.util.Scanner;

public class BigNumber {
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        long n,sum=0L,r,N=0L;
         n=s.nextLong();
        while(n!=0)
        {
            r=n%10;
            sum+=r;
            N=N*10+r;
            n/=10;
        }
        System.out.println("Sum of the digit is: "+sum);
        System.out.println("Reversed Number: "+N);
    }
}
