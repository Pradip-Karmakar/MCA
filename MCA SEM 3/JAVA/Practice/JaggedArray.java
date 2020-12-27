public class JaggedArray {
    public static void main(String[] args){
        int ja[][] = {{1,2,3},{1,2,3,4}};
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3 + i; j++)
            {
                System.out.print(ja[i][j] + " ");
            }
            System.out.println("\n");
        }
    }
}
