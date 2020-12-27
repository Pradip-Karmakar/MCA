import java.util.Scanner;

public class MinuteToYearDay {
    final static int HOUR = 24;
    final static int DAYSINYEAR = 365;
    final static int MINUTES = 60;
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Values as Minutes : ");
        long minute = scan.nextLong();
        int year = (int) (minute / ((MINUTES*HOUR)*DAYSINYEAR));
        int remainingminute = (int) (minute % ((MINUTES*HOUR)*DAYSINYEAR));
        int days = remainingminute / (MINUTES * HOUR);

        System.out.println(year + " Years and " + days + " Days.");
    }
}
