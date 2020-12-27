public class Uber2 {
    public static void main(String[] args) {
        Cab cab = new Cab() {
            
            @Override
            public void bookCab() {
                System.out.println("UberX Booked!! Arriving Soon !!");
            }
        };

        cab.bookCab();
    }
}

@FunctionalInterface
interface Cab {
    void bookCab();
}