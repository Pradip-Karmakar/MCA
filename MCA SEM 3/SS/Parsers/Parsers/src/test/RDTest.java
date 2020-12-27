package test;

import java.util.Scanner;
import parser.RecursiveDescentParser;
import parser.TreeNode;

// Compile & Run
// javac -d ../bin parser/*.java && javac -d ../bin test/*.java && java -cp ../bin test.RDTest

public class RDTest {
    public static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the Expression: ");
        String expression = scanner.nextLine();
        RecursiveDescentParser recursiveDescentParsing = new RecursiveDescentParser(expression);
        TreeNode rootNode;

        rootNode = recursiveDescentParsing.proc_E();

        if (rootNode != null) {
            rootNode.postOrderTraversal();
        }
    }
}
