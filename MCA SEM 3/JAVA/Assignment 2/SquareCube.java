public class SquareCube {
    public static void main(String[] args){
        for (int i = 1; i < 11; i++) {
            for (int j = 1; j < 4; j++) {
                System.out.print((int)Math.pow(i, j) + "  ");
            }
            System.out.println();
        }
    }
}
