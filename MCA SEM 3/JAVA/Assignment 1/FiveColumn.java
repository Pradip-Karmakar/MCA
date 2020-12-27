public class FiveColumn {
    public static void main(String[] args){
        int col = 0;
        int i = 1;
        while(i <= 100){
            if(col == 5) {
                col = 0; 
                System.out.println();
            }
            System.out.print(i++ + " ");
            col++;
        }
    }
}
