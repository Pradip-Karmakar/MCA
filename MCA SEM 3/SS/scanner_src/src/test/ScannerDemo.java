package test;

import scanner.MyScanner;

public class ScannerDemo {
    public static void main(String[] args) {
        // MyScanner sc = new MyScanner();
        // boolean check1 = sc.check("aaabbbcccddd");
        // System.out.println("aaabbbcccddd is " + (check1 ? " valid" : " not valid."));
        // System.out.println();

        // boolean check2 = sc.check("aaabcddd");
        // System.out.println("aaabcddd is " + (check2 ? " valid" : " not valid."));
        // System.out.println();

        // boolean check3 = sc.check("abcd");
        // System.out.println("abcd is " + (check3 ? " valid" : " not valid."));
        // System.out.println();

        // boolean check4 = sc.check("aaaaabbbbdddd");
        // System.out.println("aaaaabbbbdddd is " + (check4 ? " valid" : " not
        // valid."));
        // System.out.println();

        // boolean check5 = sc.check("abd");
        // System.out.println("abd is " + (check5 ? " valid" : " not valid."));
        // System.out.println();

        // boolean check6 = sc.check("aaaacccddd");
        // System.out.println("aaaacccddd is " + (check6 ? " valid" : " not valid."));
        // System.out.println();

        String[] valids = { "aaabbbcccddd", "aaabcddd", "abcd", "aaaaabbbbdddd", "abd" };
        MyScanner sc = new MyScanner(valids);
        boolean check6 = sc.check("cccddd");
        System.out.println("aaaacccddd is " + (check6 ? " valid" : " not valid."));
        System.out.println();
    }
}

// $ javac -d ../bin scanner/*.java
// javac -d ../bin test/*.java
// java -cp ../bin test.ScannerDemo

// State: start, Next States: a
// State: a, Next States: a, b
// State: b, Next States: b, c, d
// State: c, Next States: c, d
// State: d, Next States: d
// start has next state a
// a has next state a
// a has next state a
// a has next state b
// b has next state b
// b has next state b
// b has next state c
// c has next state c
// c has next state c
// c has next state d
// d has next state d
// d has next state d
// aaabbbcccddd is valid

// start has next state a
// a has next state a
// a has next state a
// a has next state b
// b has next state c
// c has next state d
// d has next state d
// d has next state d
// aaabcddd is valid

// start has next state a
// a has next state b
// b has next state c
// c has next state d
// abcd is valid

// start has next state a
// a has next state a
// a has next state a
// a has next state a
// a has next state a
// a has next state b
// b has next state b
// b has next state b
// b has next state b
// b has next state d
// d has next state d
// d has next state d
// d has next state d
// aaaaabbbbdddd is valid

// start has next state a
// a has next state b
// b has next state d
// abd is valid

// start has next state a
// a has next state a
// a has next state a
// a has next state a
// aaaacccddd is not valid.