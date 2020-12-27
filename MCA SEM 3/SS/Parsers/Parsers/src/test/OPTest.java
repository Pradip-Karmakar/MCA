package test;

import parser.OperatorPrecedenceParser;

public class OPTest {
    public static void main(String[] args) {
        String equation = "a + b * c";
        OperatorPrecedenceParser a = new OperatorPrecedenceParser();
        OperatorPrecedenceParser.TreeNode tree = a.parse(equation);

        System.out.println("Equation: " + equation);
        System.out.print("InOrder Traversal: ");
        OperatorPrecedenceParser.inOrder(tree);

        System.out.print("\nPostOrder Traversal: ");
        OperatorPrecedenceParser.postOrder(tree);
        System.out.println();

    }
}
