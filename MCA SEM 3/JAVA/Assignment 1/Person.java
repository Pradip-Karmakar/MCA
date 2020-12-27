import java.util.Scanner;
public class Person {
     private String name;
     private int age;
     private float salary;

     public void set(){
        Scanner get = new Scanner(System.in);
        System.out.print("Enter Name : ");
        name = get.nextLine();
        System.out.print("Enter Age : ");
        age = get.nextInt();
        System.out.print("Enter Salary : ");
        salary = get.nextFloat();
     } 

     public void display(){
        System.out.println("Name : " + name);
        System.out.println("Age : " + age);
        System.out.println("Salary : " + salary);
     } 

    public static void main(String[] args){
        Person person = new Person();
        person.set();
        person.display();
    } 
} 