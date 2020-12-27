public class Print17 {
    public static void main(String[] args){
        int i = 1;
        int magicNumber = 17;

        while((magicNumber*i) <= 100){
            System.out.print((magicNumber*i) + " ");
            i++;
        }
    }    
}
