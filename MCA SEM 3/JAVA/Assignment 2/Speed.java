import java.util.Scanner;
public class Speed {
    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in); 

		float seconds;
        float minutePerSecond;
        float kiloMeterPerHour;
        float milePerHour;

		System.out.print("Enter distance in meters : ");
		float distance = scan.nextFloat();

		System.out.print("Enter hour: ");
		float hr = scan.nextFloat();

		System.out.print("Enter minutes: ");
		float min = scan.nextFloat();

		System.out.print("Enter seconds: ");
		float sec = scan.nextFloat();

		seconds = (hr*3600) + (min*60) + sec;
		minutePerSecond = distance / seconds;
		kiloMeterPerHour = ( distance/1000.0f ) / ( seconds/3600.0f );
		milePerHour = kiloMeterPerHour / 1.609f;

		System.out.println("Meter/Seconds : " + minutePerSecond);
		System.out.println("KM/H : " + kiloMeterPerHour);
		System.out.println("Miles / Hour : " + milePerHour);
		
	}
}