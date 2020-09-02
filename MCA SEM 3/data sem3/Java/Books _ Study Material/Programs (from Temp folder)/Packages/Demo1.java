package mcaiii;
public class Demo1{
    public static void main(String args[]) {
        int n=10, m=11;
        //Using fully qualified name instead of import
        MyPackage.Compare current = new MyPackage.Compare(n, m);
        if(n != m) {
             current.getmax();
        }
        else {
            System.out.println("Both the values are same");
        }   
}
}