package mcaiii;
import MyPackage.Compare;
 
public class Demo{
    public static void main(String args[]) {
        int n=10, m=10;
        Compare current = new Compare(n, m);
        if(n != m) {
             current.getmax();
        }
        else {
            System.out.println("Both the values are same");
        }   
}
}