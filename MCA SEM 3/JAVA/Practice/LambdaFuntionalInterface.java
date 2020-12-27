public class LambdaFuntionalInterface {    
    public static void main(String[] args)
    {
        FuncInterface fobj  = (int x) -> System.out.println(2*x);
        fobj.abstractFun(12);
    }
}

interface FuncInterface{
    void abstractFun(int x);

    default void normalFun()
    {
        System.out.println("Hello");
    }
}