public class Uber1 {
    public static void main(String[] args) {
        Cab cab = new UberX1();
        cab.bookCab();
    }
}

@FunctionalInterface
interface Cab {
    void bookCab();
}

class UberX1 implements Cab {
    public void bookCab() {
        System.out.println("UberX Booked!! Arriving Soon !!");
    }
}