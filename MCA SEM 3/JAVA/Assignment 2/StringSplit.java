import java.util.Scanner;

public class StringSplit {
    public static void main(String[] args)
    {
    int index;
    int tmp;
    int count=0;
    String old;
    String New; 
    String token;
    Scanner s = new Scanner(System.in);

    System.out.print("Enter String: ");
    old=s.nextLine();

    System.out.print("Enter from which word you want to split: ");
    token=s.nextLine();

    index= old.indexOf(token);
    tmp=index;

    while(count<3 && tmp != -1)
    {
        tmp=old.indexOf(" ",tmp+1);
        count++;
    }

    New=old.substring(index,tmp);

    System.out.println("Old string= " + old);
    System.out.println("New string= " + New);
    
    }
}