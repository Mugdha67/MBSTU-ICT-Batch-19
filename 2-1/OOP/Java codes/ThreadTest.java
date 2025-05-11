class TA extends Thread{
    public void run(){
        for(int i = 1; i<=5; i++){
            System.out.println("From A : " + i);
        }
        System.out.println("Exit from A");
    }
}
class TB extends Thread{
    public void run(){
        for(int j = 1; j<=5; j++){
            System.out.println("From B : " + j);
        }
        System.out.println("Exit from B");
    }
}
class TC extends Thread{
    public void run(){
        for(int k = 1; k<=5; k++){
            System.out.println("From C : " + k);
        }
        System.out.println("Exit from C");
    }
}
public class ThreadTest {
    public static void main(String[] args) {
        new TA().start();
        new TB().start();
        new TC().start();
    }
}
