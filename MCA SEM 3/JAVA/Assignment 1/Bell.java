public class Bell {
    public static void main(String args[]) {
        int bellCount = Integer.parseInt(args[0]);

        while(bellCount != 0){
            System.out.println(bellCount);
            bellCount--;
        }
        System.out.print("\u0007");
    }
}
