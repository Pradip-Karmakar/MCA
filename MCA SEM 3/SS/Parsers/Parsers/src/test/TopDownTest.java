package test;

import parser.TopDownWithoutBackTrack;

public class TopDownTest {
    public static void main(String[] args) {
        System.out.println("TopDownWithoutBackTrack");
        TopDownWithoutBackTrack a = new TopDownWithoutBackTrack();

        String parsed = a.parse("a + b * c * d + e");

        System.out.println("Parsed: " + parsed);

        // System.out.println(a.replaceAt(1, "TE''", "+E", 3));
    }
}
