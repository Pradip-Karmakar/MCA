public class ExcDemo2 {
    public static void main(String[] args) {
        int[] numberSet1 = { 12, 14, 12, 6, 18, 40 };
        int[] numberSet2 = { 2, 4, 0, 6, 0, 4 };
        try {
            System.out.println("Before Exception");
            for (int i = 0; i < numberSet1.length; i++) {
                System.out.println(numberSet1[i] / numberSet2[i]);
            }
            System.out.println("this won't be displayed");
        }
        catch(ArithmeticException exc) {
            System.out.println("Divide by Zero !");
        }
        System.out.println("After catch statement");
    }
}
