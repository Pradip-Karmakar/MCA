public class AreaOfCircle {
    public static void main(String[] args)
    throws java.io.IOException{
        double pi = 3.14159;
        System.out.print("Enter The Radius : ");
        double r = (double) System.in.read() - 48;
        System.out.println("Area Of Circle : " + pi*Math.pow(r,2));
    }    
}
