public class ScopeDemo {
    public static void main(String args[])
    {
        int x;
        x = 10;
        if(x == 10)
        {
            int y = 20;
            System.out.println("X and Y : " + x + " " + y);
            x = y * 2;
        }
        // y = 100; //<-- Error Y is outside of its scope.
        System.out.println("X : " + x); // while x still known here.
    }
}
