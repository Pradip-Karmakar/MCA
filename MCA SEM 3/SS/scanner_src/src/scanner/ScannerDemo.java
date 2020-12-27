
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

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

// class State to store the state and its next states
class State {
    char symbol; // symbol for the current state
    List<Character> nextStates; // list of symbols which are the next states

    // construtor
    State(char state) {
        this.symbol = state;
        nextStates = new ArrayList<>();
    }

    // returns true if current state has a next state with given value
    boolean hasNextState(char state) {
        return this.nextStates.stream().anyMatch(ch -> ch == state);
    }

    @Override
    public String toString() {
        String state = "State: " + (symbol == (int) 0 ? "start" : symbol) + ", Next States: ";

        for (char ch : nextStates)
            state += ch + ", ";

        return state.substring(0, state.length() - 2);
    }
}

class MyScanner {
    State start;
    // State[] states; // changes from array to List
    List<State> states;

    // constructor
    public MyScanner() {
        this.initialize();
        this.createDFA();
        this.displayStates();
    }

    public MyScanner(String[] valids) {
        this.initialize(valids);
        this.displayStates();
    }

    // Initializes the start and other states
    private void initialize() {
        start = new State((char) 0);
        State[] list = new State[] { new State('a'), new State('b'), new State('c'), new State('d') };
        // this.states = list;
        states = Arrays.asList(list);
    }

    // Initializes the start and other states from list of valid strings
    private void initialize(String[] valids) {
        this.states = new ArrayList<>();
        this.start = new State((char) 0);

        for (String valid : valids) {
            State current = this.start;

            for (int i = 0; i < valid.length(); i++) {
                char ch = valid.charAt(i);

                if (this.getState(ch) == null)
                    this.states.add(new State(ch));

                if (!current.hasNextState(ch))
                    current.nextStates.add(ch);

                current = this.getState(ch);
            }
        }

    }

    // returns the State object with a given value
    private State getState(char value) {
        // for (int i = 0; i < states.length; i++) {
        // if (states[i].symbol == value)
        // return states[i];
        // }
        // return null;
        return this.states.stream().filter(state -> state.symbol == value).findAny().orElse(null);
    }

    // create the DFA/state table
    private void createDFA() {
        start.nextStates.add('a');

        State a = this.getState('a');
        a.nextStates.add('a');
        a.nextStates.add('b');

        State b = this.getState('b');
        b.nextStates.add('b');
        b.nextStates.add('c');
        b.nextStates.add('d');

        State c = this.getState('c');
        c.nextStates.add('c');
        c.nextStates.add('d');

        State d = this.getState('d');
        d.nextStates.add('d');
    }

    // display all the states in DFA with their next states
    private void displayStates() {
        System.out.println(start);

        // for (State s : states)
        // System.out.println(s);

        this.states.forEach(System.out::println);
    }

    // checks the expression and returns true/false accordingly
    public boolean check(String expression) {
        // initializes the current state from start state
        State current = start;

        // for each character in expression string
        for (int i = 0; i < expression.length(); i++) {
            char symbol = expression.charAt(i);

            // if the current state has the next state with the current symbol
            // then the expression is going fine...
            if (current.hasNextState(symbol)) {
                System.out
                        .println((current.symbol == (int) 0 ? "start" : current.symbol) + " has next state " + symbol);
                current = this.getState(symbol);
            }

            // if current state doesnt have next state with given value
            // expression is not valid
            else
                return false;
        }

        return true;
    }
}
