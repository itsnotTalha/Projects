public class UIU {
    public String StudentName;
    public String StudentID;
    private String StudentPass;
    private double cgpa;
    public int courses;
    public int credit;

    private double discount;

    public String UGName;
    public String UGID;
    private String UGPass;

    public UIU(){

    }
    public UIU(String studentName, String studentID, String studentPass){
        this.StudentName=studentName;
        this.StudentID=studentID;
        this.StudentPass=studentPass;
    }

    public void Display(){
        System.out.println("Name: "+StudentName);
        System.out.println("ID: "+StudentID);
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
