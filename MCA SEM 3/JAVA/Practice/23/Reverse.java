import java.util.Scanner;
public class Reverse {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String input = sc.nextLine();
    System.out.println(Reversed(input));   
  }

  static String Reversed(String input) {
    String retrunstring = "";
    int length = input.length();
    for(int i = ( length - 1 ); i >= 0 ; i-- ) {
      retrunstring += input.charAt(i);
    }
    return retrunstring;
  }
}