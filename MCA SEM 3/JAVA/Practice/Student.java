package basicoperation;
import java.util.Scanner;
public class Student implements math{
    @Override
    public void add() {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter any two integer values to perform addition : ");
        int a = kb.nextInt();
        int b = kb.nextInt();
        int s = a + b;
        System.out.println("Diffrence of "+a+" and "+b+" is "+s);
    }

    @Override
    public void sub() {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter any two integer values to perform subtraction : ");
        int a = kb.nextInt();
        int b = kb.nextInt();
        int s = a - b;
        System.out.println("Diffrence of "+a+" and "+b+" is "+s);
    }

    @Override
    public void mul() {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter any two integer values to perform multiplication : ");
        int a = kb.nextInt();
        int b = kb.nextInt();
        int s = a * b;
        System.out.println("Diffrence of "+a+" and "+b+" is "+s);
    }

    @Override
    public void div() {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter any two integer values to perform divition : ");
        int a = kb.nextInt();
        int b = kb.nextInt();
        int s = a / b;
        System.out.println("Diffrence of "+a+" and "+b+" is "+s);
    }
    public static void main(String[] args){
        Student stu = new Student();
        stu.add();
        stu.sub();
        stu.mul();
        stu.div();
    }
}
