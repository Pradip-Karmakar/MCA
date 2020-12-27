public class ArrayString {
    public static void main(String args[]){
        String strs [] = { "this","is","a","test."};
        System.out.print("original array : ");
        for(String s : strs)
            System.out.print(s+" ");

        System.out.println("\n");
         
        strs[1] = "was";
        strs[3] = "test , tool";
        System.out.print("Modified array : ");
        for(String s : strs)
            System.out.print(s+" ");
    }
}
