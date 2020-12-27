public class QueueDemo {
    public static void main(String args[]){
        Queue bigQ = new Queue(100);
        Queue smallQ = new Queue(4);
        char ch;

        System.out.println("Using bigQ to stire the alphabet");

        for (int i = 0; i < 26; i++) 
            bigQ.put((char) ('A' + i));

        System.out.println("Contents of bigQ: ");
        for (int i = 0; i < 26; i++) {
            ch = bigQ.get();
            if(ch != (char) 0)
                System.out.println(ch);
        }
        System.out.println("\n");

        System.out.println("Using smallQ to generate errors");
        for (int i = 0; i < 5; i++) {
            System.out.println("Attempting to store " + (char) ('Z' - i));
            smallQ.put((char) ('Z' - i));
            System.out.println();
        }
        System.out.println();

        System.out.println("Contents of smallQ : ");
        for (int i = 0; i < 5; i++) {
            ch = smallQ.get();
            if(ch != (char) 0)
                System.out.println(ch);
        }
    }
}

class Queue {
    char q[];
    int putloc;
    int getloc;

    Queue(int size) {
        q = new char[size];
        putloc = getloc = 0;
    }

    void put(char ch) {
        if(putloc == q.length) {
            System.out.println(" - Queue is Full.");
            return;
        }

        q[putloc++] = ch;
    }

    char get() {
        if(getloc == putloc) {
            System.out.println(" - Queue is Empty.");
            return (char) 0;
        }

        return q[getloc++];
    }
}
