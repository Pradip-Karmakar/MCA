public class Table {
    public static void main(String args[])
    {
        for(int i = 1; i <= Integer.parseInt(args[1]); i++)
        {
            System.out.println(args[0] + " * " + i + " = " + Integer.parseInt(args[0]) * i);
        }
    }
}
