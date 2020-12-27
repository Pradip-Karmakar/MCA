public class TryThread {
    public static void main(String[] args) {

        System.out.println("Start");

        // Try mytry = new Try();
        
        // mytry.start();

        Runnable r = new Try();
        Thread task = new Thread(r);
        task.start();

        for (int i = 1; i <= 10; i++) {
            System.out.println("@@ task : " + i);
        }

        System.out.println("End");
    }
}


class Try1 {

}

class Try extends Try1 implements Runnable {

    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println("^^ task : " + i);
        }
    }
}