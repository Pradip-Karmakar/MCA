public class FormatSpc {
    public static void main(String[] args) {
        int count = 0;
        for (int i = 'a'; i <= 'z' ; i++) {
            System.out.printf(" %1$4c%1$4x", i);
            if(++count % 6 == 0) {
                System.out.printf("%n");
            }
        }       
    }
}
