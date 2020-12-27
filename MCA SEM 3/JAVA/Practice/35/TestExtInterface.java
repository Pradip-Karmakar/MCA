package extInterface;

import java.util.Scanner;

class TestExtInterface implements ExtInterface{
    public void method1() {
        System.out.println("Implementation of Method1");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number to find the Square root in java:");
        double square = sc.nextDouble();
        double squareRoot = Math.sqrt(square);
        System.out.printf("Square root of number: %f is -> %f",square,squareRoot);
        
    }
    public void method2() {
        System.out.println("Implementation of method2");
    }
    public static void main(String[] args) {
        ExtInterface obj  = new TestExtInterface();
        obj.method1();
    }
}