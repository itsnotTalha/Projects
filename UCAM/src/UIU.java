import java.util.Scanner;

public class UIU {
    Scanner scan = new Scanner(System.in);
    public String StudentName;
    public String StudentID;
    private String StudentPass;
    private double cgpa;
    public int courses;
    public int credit;
    public int total_credit;

    private double discount;

    public String UGName;
    public String UGID;
    private String UGPass;

    public UIU(){

    }
    public UIU(String ugID, String ugPass){
        System.out.print("Enter UG name: ");
        this.UGName=scan.nextLine();
        this.UGID=ugID;
        this.UGPass=ugPass;
    }

    public UIU(String studentName, String studentID, String studentPass){
        this.StudentName=studentName;
        this.StudentID=studentID;
        this.StudentPass=studentPass;
    }

    public boolean checkPass() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Your password: ");
        String pass = scan.next();
        if (pass.equals(StudentPass)) {
            return true;
        } else if (pass.equals(UGPass)) {
            return true;
        } else {
            return false;
        }
    }
    public void Display(){
        if(checkPass()){
        System.out.println("Name: "+StudentName);
        System.out.println("ID: "+StudentID);
            System.out.println("Completed Credit: "+total_credit);
            System.out.println("CGPA: "+cgpa);
        }
    }

    public String getStudentPass() {
        return StudentPass;
    }

    public void setStudentPass(String studentPass) {
        StudentPass = studentPass;
    }

    public double getCgpa() {
        return cgpa;
    }

    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }

    public String getUGPass() {
        return UGPass;
    }

    public void setUGPass(String UGPass) {
        this.UGPass = UGPass;
    }

    public double getDiscount() {
        return discount;
    }

    public void setDiscount(double discount) {
        this.discount = discount;
    }
}
