public class Demo {
    public static void main(String[] args) {
        MyClass m1 = new MyClass();
        m1.start();

        MyClass m2 = new MyClass();
        m2.start();
    }
}

class MyClass extends Thread {
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getId() + " Value " + i);
        }
        try{
            Thread.sleep(1000);
        } catch (InterruptedException e){
            e.printStackTrace();
        }
    }
}