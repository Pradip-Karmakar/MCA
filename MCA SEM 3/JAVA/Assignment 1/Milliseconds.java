import java.util.Calendar;
public class Milliseconds {
    final static byte HOURS = 24;
    final static byte MINUTE = 60;
    final static byte SECONDS = 60;
    final static short MILLISECONDS = 1000;
    public static void main(String[] args) {

        Calendar date = Calendar.getInstance();
        int currentHour = date.get(Calendar.HOUR_OF_DAY);
        int currentMinute = date.get(Calendar.MINUTE);
        int currentSecond = date.get(Calendar.SECOND);
        int currentMillisecond = date.get(Calendar.MILLISECOND);
        System.out.println("Current Time : " + currentHour + ":" + currentMinute + ":" + currentSecond + ":" + currentMillisecond);
        
        long tillMidnightMilliseconds = ( (HOURS - currentHour - 1) * MINUTE * SECONDS * MILLISECONDS ) + ((MINUTE - currentMinute ) * SECONDS * MILLISECONDS) + ((SECONDS - currentSecond ) * MILLISECONDS) + (MILLISECONDS - currentMillisecond);
        System.out.println("Milliseconds Remain till Midnight: " + tillMidnightMilliseconds);
    } 
}
