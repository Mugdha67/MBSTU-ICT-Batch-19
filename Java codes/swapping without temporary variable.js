import java.util.*;
class swapping
{
   public static void main(String[] args)
      {
           int a,b;
           Scanner sc=new Scanner(System.in);
           System.out.println("Enter two numbers:");
           a=sc.nextInt();
           b=sc.nextInt();
           System.out.println("Before swapping:");
           System.out.println("a="+a);
           System.out.println("b="+b);
	   if(a>b)
	    {
		a=a+b;
                b=a-b;
		a=a-b;
            }
           else
	    {
		b=a+b;
                a=b-a;
		b=b-a;
	    }
            System.out.println("After swapping:");
            System.out.println("a="+a);
            System.out.println("b="+b);
       }
}