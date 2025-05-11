import java.util.*;
public class practice{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        double sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=((1.0)/i);
        }
        System.out.printf("%.2lf\n",sum);
    }
}