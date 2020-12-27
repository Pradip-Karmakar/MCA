import java.util.Scanner;

public class WordReverse {
    public static void main(String[] args) {
        String input;
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter String : ");
        input = scan.nextLine();

        String token[] = input.split(" ");
        System.out.println("Count of words in String : " + token.length);

        for (int i = token.length - 1; i >= 0; i--) {
            System.out.print(token[i] + " ");
        }
    }
}
