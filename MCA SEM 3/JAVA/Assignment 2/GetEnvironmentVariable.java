import java.lang.*;
public class GetEnvironmentVariable {
    public static void main(String[] args)
    {
        System.out.println("\nEnvironment variable USERNAME: ");
        System.out.println(System.getenv("USERNAME"));

        System.out.println("\nEnvironment variable TEMP: ");
        System.out.println(System.getenv("TEMP"));

        System.out.println("\nEnvironment variable PATH: ");
        System.out.println(System.getenv("PATH"));
        
    }
}

