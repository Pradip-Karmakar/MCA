public class OneZeroPattern {
    public static void main(String[] args) {
        int setter = 1;
        int numberOflines = 9;
        for (int i = 0; i < numberOflines; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(setter);
                if(setter == 1) setter = 0;
                else setter = 1;
            }
            System.out.println("");
        }
    }
}
