public class DemoRun {
    public static void main(String[] args) {
        Thread T1 = new Thread(new MyClass1());
        Thread T2 = new Thread(new MyClass1());
        
        T1.start();
        T2.start();
    }
}

class MyClass1 implements Runnable {
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getId() + " Value " + i);
        }
        try{
            Thread.sleep(100);
        } catch (InterruptedException e){
            e.printStackTrace();
        }
    }
}