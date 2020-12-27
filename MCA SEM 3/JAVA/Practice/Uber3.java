public class Uber3 {
    public static void main(String[] args) {
        Cab cab = () -> System.out.println("UberX Booked!! Arriving Soon !!");
        cab.bookCab();
    }
}

@FunctionalInterface
interface Cab {
    void bookCab();
}