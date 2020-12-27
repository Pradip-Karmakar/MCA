public class FunctionalLambda {
    interface IntegerMath {
        int operation(int a, int b);
    }

    public int operateBinary(int a, int b, IntegerMath op) {
        return op.operation(a, b);
    }

    public static void main(String[] args) {
        FunctionalLambda myApp = new FunctionalLambda();

        IntegerMath addition = (a, b) -> a + b;
        IntegerMath subtraction = (a, b) -> a - b;
        IntegerMath multiplication = (a, b) -> a * b;
        IntegerMath division = (a, b) -> a / b;

        int a = 10, b = 5;

        System.out.println(a + " + " + b + " = " + myApp.operateBinary(a, b, addition));
        System.out.println(a + " - " + b + " = " + myApp.operateBinary(a, b, subtraction));
        System.out.println(a + " * " + b + " = " + myApp.operateBinary(a, b, multiplication));
        System.out.println(a + " / " + b + " = " + myApp.operateBinary(a, b, division));
    }
}