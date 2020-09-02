class MyClass1 implements Runnable { 
	public void run() {
		for (int i=0;i<10;i++) {
			System.out.println(Thread.currentThread().getId() +  "  value   " + i);
		}
		  try {
			Thread.sleep(100);
		 } catch (InterruptedException e) {
			e.printStackTrace();
		} 
	}
} 

public class Demo_run1	{
	public static void main (String[] args) {
	/*	Thread t1=new Thread(new Runnable() {
		
		public void run() {
			for (int i=0;i<10;i++) {
			System.out.println(Thread.currentThread().getId() +  "  value   " + i);
			}
		  try {
			Thread.sleep(100);
		 } catch (InterruptedException e) {
			e.printStackTrace();
		} 
	}
	
	
	};
*/
 
//	MyClass m1=new MyClass();
//	t1.start();
	
	
	Thread T2=new Thread(new MyClass1());
		
		MyClass m1=new MyClass();
		T2.start();
		//T2.start();
		//MyClass m2=new MyClass();
		
	
}
}