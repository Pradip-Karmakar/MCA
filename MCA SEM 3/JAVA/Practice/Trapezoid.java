public class Trapezoid {
    public static void main(String[] args) {
        Square tapez =new Square();
        System.out.println(tapez.calculate());
    }
}

public  class Square {
    private double height;
    private double base1;
    private double base2;
    public Square() {
        this.height = getHeight();
        this.base1 = getBase1();
        this.base2 = getBase1(); 
    }
    double getHeight() {
        return 4;
    }
    double getBase1() {
        return 3;
    }
    double getBase2() {
        return 3;
    }
    double calculate() {
        return 0.5 * this.height * (this.base1 + this.base2);
    }
}