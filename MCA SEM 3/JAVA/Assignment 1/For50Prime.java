public class For50Prime {
    public static void main(String[] args) {
        System.out.println("50 Prime Numbers using For Loop");
        ForPrime();
        System.out.println();
        System.out.println("50 Prime Numbers using While Loop");
        WhilePrime();
        System.out.println();
        System.out.println("50 Prime Numbers using Do-While Loop");
        DoWhilePrime();
    }


    public static void ForPrime() {
        boolean checkPrime = false;
        int count = 1;

        for(int i = 2; count < 51; i++){
            int sqroot = (int)Math.sqrt(i);
            for(int j = 2; j <= sqroot; j++)
            {
                if(i % j == 0)
                {
                    checkPrime = true;
                    break;
                }
            }
            if(!checkPrime){
                System.out.println(count + " = " + i);
                count++;
            }
            else
                checkPrime = false;
        }
    }


    public static void WhilePrime() {
        boolean checkPrime = false;
        int count = 1;
        int i = 2;
        while(count < 51) {
            int sqroot = (int)Math.sqrt(i);
            int j = 2;
            while(j <= sqroot)
            {
                if(i % j == 0)
                {
                    checkPrime = true;
                    break;
                }
                j++;
            }
            if(!checkPrime){
                System.out.println(count + " = " + i);
                count++;
            }
            else checkPrime = false;

            i++;
        }
    }

    public static void DoWhilePrime() {
        boolean checkPrime = false;
        int count = 1;
        int i = 2;
        do{
            int sqroot = (int)Math.sqrt(i);
            int j = 2;
            while(j <= sqroot) {
                if(i % j == 0)
                {
                    checkPrime = true;
                    break;
                }
                j++;
            }
            if(!checkPrime){
                System.out.println(count + " = " + i);
                count++;
            }
            else checkPrime = false;

            i++;
        }while(count < 51); 
    }

}