public class PosibleFactors {
    public static void main(String args[]){
        int number = Integer.parseInt(args[0]);
        int i = 1; 
        while(i <= (number/2)){
            if( number % i == 0 ) 
                System.out.print(i + " ");
            
            i++;
        }
        System.out.print(number);
    }    
}
