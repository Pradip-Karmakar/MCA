import static java.lang.Integer.toBinaryString;
public class BitwiseOperator {
    public static void main(String[] args) {
        int indicators = 0xFF07;
        int selectBit3 = 0x4;
        System.out.println("indicators = " + toBinaryString(indicators));
        System.out.println("selectBit3 = " + toBinaryString(selectBit3));
        indicators &= selectBit3;
        System.out.println("indicators & selectBit3 = " + toBinaryString(indicators));
        indicators = 0xFF09;
        System.out.println("\nindicators = " + toBinaryString(indicators));
        System.out.println("selectBit3 = " + toBinaryString(selectBit3));
        indicators |= selectBit3;
        System.out.println("indicators | selectBit3 = " + toBinaryString(indicators));
        indicators &= ~selectBit3;
        System.out.println("\nThe third bit in the previous value of indicators" + " has been switched off");
        System.out.println("indicators & ~selectBit3 = " + toBinaryString(indicators));
    }
}
