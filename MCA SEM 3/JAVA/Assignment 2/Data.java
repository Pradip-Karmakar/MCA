public class Data {
    public static void main(String[] args) {
        Employee emp1 = new Manager(101, "Pradip", "Karmakar", 30_00_0F, "Product Manager", 6);
        Employee emp2 = new Clerk(201, "Sudip", "Karmakar", 10_00_0F, "Production", 300);
        Employee emp3 = new Manager(102, "Sandip", "Karmakar", 23_00_0F, "Sales Manager", 2);
        Employee emp4 = new Clerk(202, "Jeet", "Karmakar", 30_00_0F, "Sales", 240);
        Employee emp5 = new Manager(103, "Samar", "Karmakar", 40_00_0F, "Human Resource Manager", 12); 
        emp1.CalculateBonus();
        emp1.PrintDetail();
        emp2.CalculateBonus();
        emp2.PrintDetail();
        emp3.CalculateBonus();
        emp3.PrintDetail();
        emp4.CalculateBonus();
        emp4.PrintDetail();
        emp5.CalculateBonus();
        emp5.PrintDetail();
    }
}

abstract class Employee {
    int empid;
    String fname;
    String lname;
    float salary;
    String designation;
    float bonus;

    public Employee() {
        empid = 0;
        fname = "Not Specified";
        lname = "Not Specified";
        salary = 0.0F;
        designation = "Not Specified";
        bonus = 0.0F;
    }

    public Employee(int empid, String fname, String lname, float salary, String designation) {
        this.empid = empid;
        this.fname = fname;
        this.lname = lname;
        this.salary = salary;
        this.designation = designation;
    }

    public abstract void CalculateBonus();
    public abstract void PrintDetail();
}

class Manager extends Employee {
    int noOfProjectsHandled;

    Manager() {
        super();
    }
    Manager(int empid, String fname, String lname, float salary, String designation, int noOfProjectsHandled) {
        super(empid, fname, lname, salary, designation);
        this.noOfProjectsHandled = noOfProjectsHandled;
    }

    public void CalculateBonus() {
            this.bonus = (noOfProjectsHandled * 1000);
    }

    public void PrintDetail() {
        System.out.println("Employee Id : " + this.empid);
        System.out.println("Name : " + this.fname + " " + this.lname);
        System.out.println("Salary : "+ this.salary);
        System.out.println("Designation : " + this.designation);
        System.out.println("Total Projects Handeled : " + this.noOfProjectsHandled);
        System.out.println("Bonus : " + this.bonus);
        System.out.println("++++++++++++++++++++++++");
    }
}

class Clerk extends Employee {
    int noOfHoursworked;

    Clerk() {
        super();
    }
    Clerk(int empid, String fname, String lname, float salary, String designation, int noOfHoursworked) {
        super(empid, fname, lname, salary, designation);
        this.noOfHoursworked = noOfHoursworked;
    }

    public void CalculateBonus() {
        if(this.noOfHoursworked > 250) {
            this.bonus = (noOfHoursworked - 250) * 200;
        }
    }

    public void PrintDetail() {
        System.out.println("Employee Id : " + this.empid);
        System.out.println("Name : " + this.fname + " " + this.lname);
        System.out.println("Salary : "+ this.salary);
        System.out.println("Designation : " + this.designation);
        System.out.println("Total Hours Worked : " + this.noOfHoursworked);
        System.out.println("Bonus : " + this.bonus);
        System.out.println("++++++++++++++++++++++++");
    }
}

