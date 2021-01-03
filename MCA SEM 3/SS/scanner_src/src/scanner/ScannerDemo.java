import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class ScannerDemo {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        // aa*(c/d)+(bd)*
        // a+b+c*d+
        // ac , aacb ,  aab , ad7 , a7cd
        boolean check = sc.check("ac");
        System.out.println("ac is " + (check ? " valid" : " not valid."));
        System.out.println();

        check = sc.check("acd");
        System.out.println("acd is " + (check ? " valid" : " not valid."));
        System.out.println();

        check = sc.check("aab");
        System.out.println("aab is " + (check ? " valid" : " not valid."));
        System.out.println();

        check = sc.check("ad7");
        System.out.println("ad7 is " + (check ? " valid" : " not valid."));
        System.out.println();

        check = sc.check("a7cd");
        System.out.println("a7cd is " + (check ? " valid" : " not valid."));
        System.out.println();
    }
}


class State {
    char symbol; 
    List<Character> nextStates;

   
    State(char state) {
        this.symbol = state;
        nextStates = new ArrayList<>();
    }

   
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

    private void initialize() {
        start = new State((char) 0);
        State[] list = new State[] { new State('a'), new State('b'), new State('c'), new State('d') };

        states = Arrays.asList(list);
    }


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

    // return refrence of state
    private State getState(char value) {
        return this.states.stream().filter(state -> state.symbol == value).findAny().orElse(null);
    }

    //  aa*(c/d)+(bd)*
    private void createDFA() {
        start.nextStates.add('a');

        State a = this.getState('a');
        a.nextStates.add('a');
        a.nextStates.add('c');
        a.nextStates.add('d');

        State c = this.getState('c');
        c.nextStates.add('b');
        c.nextStates.add('d');


        State d = this.getState('d');
        d.nextStates.add('b');

        State b = this.getState('b');
        d.nextStates.add('d');

    }


    private void displayStates() {
        System.out.println(start);
        this.states.forEach(System.out::println);
    }


    public boolean check(String expression) {
        State current = start;

        for (int i = 0; i < expression.length(); i++) {
            char symbol = expression.charAt(i);

    
            if (current.hasNextState(symbol)) {
                System.out.println((current.symbol == (int) 0 ? "start" : current.symbol) + " has next state " + symbol);
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
