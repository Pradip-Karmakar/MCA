public class RandomBreakfast {
    enum breakfast{Scrambled_Eggs, Waffles, Fruits, Cereal, Toast, Yogurt}
	
	public static void main(String args[]){
		
		int choice = (int) (Math.random()*6);
		
		System.out.println(breakfast.values()[choice]);
		
	}
}
