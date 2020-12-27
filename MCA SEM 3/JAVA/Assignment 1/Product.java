public class Product {
    public static void main(String args[]){
        int i = 0;
        double total = 1;
        while(i < args.length){
            total *= Double.parseDouble(args[i]);
            i++;
        }
        System.out.println("Product : " + total);
    }
}
