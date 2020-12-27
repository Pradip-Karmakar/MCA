public class Lottery {
    public static void main(String args[])
    {
        int [] numbers = new int[5];
        int random_number;
        boolean flag;


        for(int i = 0; i < 5; i++)
        {
            flag = false;
            random_number = (int) (Math.random()*49);
            for(int j = 0; j < i; j++)
            {
                if(numbers[j] == random_number)
                    flag = true;
            }

            if(!flag && random_number != 0){
                numbers[i] = random_number;
                System.out.println(numbers[i]);
            }
            else
                --i;
        
        }
    }
}
