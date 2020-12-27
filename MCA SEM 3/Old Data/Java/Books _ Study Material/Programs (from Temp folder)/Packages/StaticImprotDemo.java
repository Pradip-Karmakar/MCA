package MyPackage;
import static java.lang.Math.*; //static import
import static java.lang.System.*;// static import
public class StaticImportDemo {
       public static void main(String args[]) {
          double val = 64.0;
          double sqroot = sqrt(val); // Access sqrt() method directly
          out.println("Sq. root of " + val + " is " + sqroot);
          //We don't need to use 'System.out
       }
    }