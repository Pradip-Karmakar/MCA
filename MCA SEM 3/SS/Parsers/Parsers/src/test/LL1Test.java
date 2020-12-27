package test;

import parser.LL1Parser;

public class LL1Test {
    public static void main(String[] args) {
        System.out.println("LL1Parser");
        LL1Parser a = new LL1Parser();

        String parsed = a.parse("a * b + c");

        System.out.println("Parsed: " + parsed);

        // System.out.println(a.replaceAt(1, "TE''", "+E", 3));
    }
}
