import static java.lang.Long.*;
public class OperationOnBits {
    public static void main(String[] args) {
        long number = 0xF00000000000000FL;
        System.out.println("Number : " + toBinaryString(number));
        long result = rotateLeft(number,2);
        System.out.println("Number rotated left 2 bits : " + toBinaryString(result));
        result = rotateRight(number, 3);
        System.out.println("Number rotated right 3 bits : " + toBinaryString(result));
        result = reverse(result);
        System.out.println("Previous result reversed : " + toBinaryString(result));
        System.out.println("Bit count in number : " + bitCount(number));
        }
}
