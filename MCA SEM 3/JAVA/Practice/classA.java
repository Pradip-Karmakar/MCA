package Prac_Pakages;
public class classA implements Solution {
    public void Hello(){ 
        System.out.println("Hello World");
    }
    public void Welcome(){
        System.out.println("Welcome MCAIII");
    }

    public static void main(String[] args) {
        classA test = new classA();
        test.Hello();
        test.Welcome();
    }
} 