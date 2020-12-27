import java.util.Scanner;
public class MatrixAddition {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Number Of Rows : ");
        byte row = scan.nextByte();
        System.out.print("Enter Number Of Columns : ");
        byte col = scan.nextByte();
        int[][] matrixOne = new int[row][col];
        int[][] matrixTwo = new int[row][col];

        System.out.println("Matrix 1");
        getMatrix(matrixOne,row,col);
        System.out.println("Matrix 2");
        getMatrix(matrixTwo,row,col);
        addAndDisplayMatrix(matrixOne, matrixTwo, row, col);
    }

    private static void getMatrix(int[][] matrix,byte row,byte col) {
        Scanner scan = new Scanner(System.in);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print("Enter Number for Matrix [" + i + "][" + j + "] : ");
                matrix[i][j] = scan.nextInt();
            }
        }
    }

    private static void addAndDisplayMatrix(int[][] matrix1,int[][] matrix2,byte row,byte col) {
        System.out.println("Final Matrix");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(matrix1[i][j]+matrix2[i][j] + " ");
            }
            System.out.println();
        }
    }
}

    
