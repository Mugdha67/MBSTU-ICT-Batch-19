import java.util.List;
import java.util.Scanner;

/**
 * Created by User PC on 6/9/16.
 */
public class ConsoleInput  {
    public static void main(String[] args)
    {
        System.out.println("Name: ");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        //System.out.print(name);
        ServiceClass serviceClass = new ServiceClass();
        serviceClass.InsetDB(name);

        List<Student> students = serviceClass.ReadFromDB();

        if (students!=null){
            for(int i=0; i<students.size(); i++){
                Student std = students.get(i);
                System.out.println(std.getId()+" "+std.getName());
            }
        }

    }
}
