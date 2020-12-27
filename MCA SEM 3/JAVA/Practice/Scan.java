import java.util.Scanner;
public class Scan {
    public static void main(String args[]) throws java.io.IOException {	
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Your Name : ");
		String name = scanner.nextLine();
		System.out.print("Enter Your age : ");
		int age = scanner.nextInt();
		System.out.print("Enter Your salary : ");
		double salary = scanner.nextDouble();
		System.out.println("Name is:" + name);
		System.out.println("Age  is:" + age);
		System.out.println("Salary is:" + salary);
		
	}
}
