import java.util.Scanner;

public class UG extends UIU {
    Scanner scan = new Scanner(System.in);
    public String UGname;

    public UG (String name, String ID){
        this.UGname=name;
        super.UGName=name;
        super.UGID=ID;
        System.out.print("Enter a password: ");
        super.setUGPass(scan.next());
    }

}
