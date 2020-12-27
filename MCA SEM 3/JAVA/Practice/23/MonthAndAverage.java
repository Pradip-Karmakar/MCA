public class MonthAndAverage {
    public static void main(String args[]) {
        String[] monthNames = {
                               "January"  , "February", "March"   , "April",
                               "May"      , "June"    , "July"    , "August", 
                               "September","October"  , "November", "December"
                             };
                            
        double average = 0.0;
        double[] numbers = new double[12];
    
        for(int i = 0 ; i<numbers.length ; i++) {
          numbers[i] = Math.random()*100.0;
          System.out.println(monthNames[i] + " Generated  " + numbers[i]);
          average += numbers[i];
        }
        average /= numbers.length;
    
        System.out.println("\nAverage of Random Generated numbers is " + average);
      }
}
