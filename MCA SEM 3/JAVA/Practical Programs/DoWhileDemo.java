public class DoWhileDemo {
    public static void main(String args[])
    throws java.io.IOException {
        char ch;
        char ignore;
        do{
                System.out.println("Press a key Followed by Enter : ");
                ch = (char) System.in.read();
                do{
                    ignore = (char) System.in.read();
                }while(ignore != '\n');
        }while(ch != 'q');
    }
}
