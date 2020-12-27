class CheckPrime {
    public static void main(String args[])
    {
        boolean flag = false;
        int number = Integer.parseInt(args[0]);	
        int sqroot = (int)Math.sqrt(number);

        for(int i = 2; i <= sqroot; i++)
        {
            if(number % i == 0)
            {
                flag = true;
                break;
            }
        }

        if(!flag)
            System.out.println(number + " a Prime Number.");			
        else
            System.out.println(number + " is not a Prime Number.");	
    }
}
