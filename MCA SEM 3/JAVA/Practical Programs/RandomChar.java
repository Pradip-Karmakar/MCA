public class RandomChar {
    public static void main(String args[]){
        char character;
        int random_len = (int) (Math.random()*20);
        for(int i = 0; i < random_len; i++)
        { 
            character = (char) ((Math.random()*26) + 65);
            if( character != 65 && character != 69 && character != 73 && character != 79 && character != 85)
                System.out.print(character);
        } 
    }
}