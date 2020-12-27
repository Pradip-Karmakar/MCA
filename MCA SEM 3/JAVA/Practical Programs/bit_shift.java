public class bit_shift {
    public static void main(String[] args){
        int a = 58;
        int b = 13;
        int n1 = 8;
        int n2 = -10;

        System.out.println(a&b);
        System.out.println(a|b);
        System.out.println(a^b);
        System.out.println(~a);
        System.out.println(a<<2);
        System.out.println(a>>2);
        System.out.println(a>>>2);

        System.out.println("n1 << 2 = " + (n1 << 2));
        System.out.println("n2 >> 2 = " + (n2 >> 2));
        System.out.println("n2 >>> 2 = " + (n2 >>> 2));
    }
}
