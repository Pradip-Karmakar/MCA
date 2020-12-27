public class IfDemo {
    public static void main(String args[])
    {
        int a, b, c;
        a = 2;
        b = 3;
        if(a < b)
            System.out.println("A is Smaller \n");

        if(a == b)
            System.out.println("A And B is equal \n");

        c = a - b;
        System.out.println("C contains " + c);

        if(c >= 0)
            System.out.println("C is Non-Negative \n");

        if(c < 0)
            System.out.println("C is Negative \n");

        c = b - a;
        System.out.println("C contains " + c);

        if(c >= 0)
            System.out.println("C is Non-Negative \n");

        if(c < 0)
            System.out.println("C is Negative \n");       

    }
}
