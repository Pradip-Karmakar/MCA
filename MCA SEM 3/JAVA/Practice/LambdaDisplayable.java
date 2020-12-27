public class LambdaDisplayable implements displayble {
    public void display(String msg){
        System.out.println(msg);
    }
    public static void main(String[] args) {
        LambdaDisplayable dis = new LambdaDisplayable();
        dis.display("Welcome to the World.");
        
    }
        
}
interface displayble {
    void display(String  msg); 

}
