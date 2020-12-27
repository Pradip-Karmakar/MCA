public class UntilSOccurs {
    public static void main(String args[])
    throws java.io.IOException{
        int i;
        char ignore;
        System.out.println("Press S to Stop.");
        for(i = 0; (char) System.in.read() != 'S'; i++)
        {
            if((char) System.in.read() != '\n')
            {
                System.out.println("Pass #" + i);
            }
            do{
                ignore = (char) System.in.read();
            }while(ignore != '\n');
        }
    }
}
