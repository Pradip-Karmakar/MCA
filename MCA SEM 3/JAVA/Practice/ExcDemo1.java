class ExcDemo1 {
    public static void main(String[] args) {
        int[] numbers = new int[9];
        try {
            System.out.println("Before Exception");
            numbers[10] = 200;
            System.out.println("this won't be displayed");
        }
        catch(ArrayIndexOutOfBoundsException exc) {
            System.out.println("index out-of bound !");
        }
        System.out.println("After catch statement");
    }
}