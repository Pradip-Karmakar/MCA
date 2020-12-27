package Practice;

public class ThreeDeminsion {
    public static void main(String args[]){
        int arr[][][] = { { {2,7,9},{3,6,1},{7,4,2} }, { {3,6,1},{2,7,9},{7,4,2} },{ {2,7,9},{7,4,2},{3,6,1} } };
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    System.out.print(arr[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
