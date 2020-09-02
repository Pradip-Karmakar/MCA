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

public class Demo_run	{
	public static void main (String[] args) {
		Thread T1=new Thread(new MyClass1());
		Thread T2=new Thread(new MyClass1());
		
		//MyClass m1=new MyClass();
		T1.start();
		T2.start();
		//MyClass m2=new MyClass();
		
	}
}