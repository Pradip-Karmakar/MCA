import java.util.Random; 
public class MagicHat {
    static int maxRabbits = 5; 
    static Random select = new Random(); 
   
    public MagicHat(String hatName) {
        this.hatName = hatName; 
        rabbits = new Rabbit[1+select.nextInt(maxRabbits)];
        for(int i = 0; i < rabbits.length; i++) {
        rabbits[i] = new Rabbit();
        }
    }
    
    public String toString() {
       
        String hatString = "\n" + hatName + " contains:\n";
        for(Rabbit rabbit : rabbits) {
            hatString += " " + rabbit;
        }
    return hatString;
    }
    private String hatName; 
    private Rabbit rabbits[]; 
   
    static class Rabbit {
   
    }

    static public void main(String[] args) {
        System.out.println(new MagicHat("Gray Topper"));
        System.out.println(new MagicHat("Black Topper"));
        System.out.println(new MagicHat("Baseball Cap"));
        MagicHat oldHat = new MagicHat("Old hat"); 
    }
}