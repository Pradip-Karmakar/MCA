public class StringCollection {
    public static void main(String[] args){
        String Phrase = "The Quick Brown fox Jumped over the lazy dog";
        int vowels = 0;
        for(char ch : Phrase.toCharArray()){
            ch = Character.toLowerCase(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')            
                ++vowels;
        }
        System.out.println("The Phrase contains " + vowels + " Vowels");
    }    
}
