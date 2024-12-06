import java.util.Scanner;

public class Student extends UIU {
    Scanner scan = new Scanner(System.in);

    public Student(){
        System.out.println("Enter your name: ");
        StudentName = scan.nextLine();
        System.out.println("Enter your ID: ");
        StudentID = scan.next();
        System.out.println("Enter your password: ");
        setStudentPass(scan.next());
    }


}
