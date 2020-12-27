public class Floyd {
    public static void main(String[] args) 
    throws java.io.IOException {
        int linecount = (int) System.in.read() - 48;
        boolean flag = true;
        for(int i = 0; i < linecount; i++){
        for(int j = 0; j <= i; j++){
                if(flag) {
                System.out.print("1");
            flag = false;
            }
            else{
                System.out.print("0");
            flag = true;
            }
        }
        System.out.println();
        }
    }
}
