import java.util.Arrays;
public class RemoveDuplicate {
    public static void main(String[] args) {
        char[] myString = "Pradip Karmakar".toCharArray();
        System.out.println(StringSlash(myString));
    }

    private static String StringSlash(char[] myString) {
        int index = 0;
        int j;
        for (int i = 0; i < myString.length; i++) {

            for (j = 0; j < i; j++) {
                if (myString[i] == myString[j]) 
                { 
                    break; 
                } 
            }

            if(j == i){
                myString[index++] = myString[i];
            }
        } 
        return String.valueOf(Arrays.copyOf(myString, index));  
    }
}
