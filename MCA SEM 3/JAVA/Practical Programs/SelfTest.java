import java.util.Scanner;
public class SelfTest {
    public static void main(String[] args)
    {
        String input;
        char ch;
        Scanner scan = new Scanner(System.in);
        input = scan.nextLine();
        for(int i = 0; i < input.length(); i++)
        {
            ch = input.charAt(i);
            if(ch > 64 && ch < 91)
            {
                ch += 32;
                System.out.print(ch);
            }
            else{
                ch-=32;
                System.out.print(ch);
            }
        }
    }
}
