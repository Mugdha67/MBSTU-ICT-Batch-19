import java.util.*;
public class difference {
    public static void main(String[] args) {
        int[] n = new int[50];
        int M=0,c=0;
        Random random = new Random();
        for (int i = 0; i < 50; i++) {
            n[i] = random.nextInt(100) + 1;
        }
        for (int i = 0; i < 49; i++) {
            int x=Math.abs(n[i]-n[i+1]);
            if(x>M)
            {
                M=x;
            }
            if(x==2) c++;
        }
        System.out.println("Maximum difference is: "+M);
        double y=((double)c/49)*100;
        System.out.println("The percentage of the difference is 2 is :"+y+"%");
    }
}
