public class Tables {
    final static int TABLESIZE = 12;
    public static void main(String[]args) {
      int[][] table = new int[TABLESIZE][TABLESIZE];
  
      for(int i = 0 ; i<table.length ; i++) {
        for(int j = 0 ; j<table[i].length ; j++) 
            table[i][j] = (i+1)*(j+1);
      }
  
      System.out.print("       ");

      for(int j = 1 ; j<=table[0].length ; j++) {
        System.out.print((j<10 ? "   ": "  ") + j);
      }

      System.out.println("\n-------------------------------------------------------");
      
      for(int i=0; i<table.length; i++) {
        System.out.print("Row" + (i<9 ? "  ":" ") + (i+1) + ":");
  
        for(int j=0; j<table[i].length; j++) {
              System.out.print((table[i][j]<10 ? "   " : table[i][j]<100 ? "  " : " ") + table[i][j]);
        }

        System.out.println();
      }
    }
  }
  
  