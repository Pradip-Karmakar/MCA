import java.io.*;
public class Assembly {
    public static void main(String[] args) throws NumberFormatException {
        String assemCode[][] = { {"","START","200",""},
                                 {"","MOVER","AREG","='5'"},
                                 {"","MOVEM","AREG","A"},
                                 {"LOOP","MOVER","AREG","A"}
                               };
        Opcode op = new Opcode();
        Symbol sym = new Symbol();
        Literal lit = new Literal();
        Register reg = new Register();
        Operations opera = new Operations();
        int checkLine = 0;
        int locationCounter = 0;
        boolean check = true;
        while(checkLine != 4) {
            System.out.println("Hello");
            if( !assemCode[checkLine][1].equals("START")) {
                locationCounter = Integer.parseInt(assemCode[checkLine][2]);
                checkLine++;
                continue;
            }
            else if( !assemCode[checkLine][1].equals("LTORG") ) {
                    ++locationCounter;
                char first = assemCode[checkLine][2].charAt(0);
                while(first == 61 && assemCode[checkLine][1].equals("\0")) {
                    checkLine++;
                    locationCounter++;
                }
            }
            else {
                if( !assemCode[checkLine][0].equals("\0")) {
                    check = sym.checkSymbol(assemCode[checkLine][0],0);
                    if(!check) {
                        sym.setSymbol(assemCode[checkLine][0]);
                    }
                }

                if( !assemCode[checkLine][1].equals("\0") ) {
                    check = op.checkOp(assemCode[checkLine][1]);
                    if(!check){
                        System.out.println("Error");
                    }
                }

                if( !assemCode[checkLine][2].equals("\0") ) {
                    check = reg.checkReg(assemCode[checkLine][2]);
                    if(!check) {
                        check = opera.checkopera(assemCode[checkLine][2]);
                    }
                }

                if( !assemCode[checkLine][2].equals("\0") ) {
                    char first = assemCode[checkLine][3].charAt(0);
                    if(first > 64 && first < 91) {
                        check = sym.checkSymbol(assemCode[checkLine][3],3);
                        if(!check) {
                            int state = sym.setSymbolret(assemCode[checkLine][3]);
                            System.out.print("(S, 0" + state + ")");
                        }
                    }
                    else if(first == 61) {
                        check = lit.checkLit(assemCode[checkLine][3]);
                        if(!check) {
                            char leteral = assemCode[checkLine][3].charAt(2);
                            lit.setLiteral(leteral);
                        }
                    }
                }
            
            }  
            checkLine++;
        }
    }
}

public class Opcode {
    private String opcodeTable[][] = { {"00","STOP","IS"},  
                                        {"01","ADD","IS"},
                                        {"02","SUB","IS"},
                                        {"03","MULT","IS"},
                                        {"04","MOVER","IS"},
                                        {"05","MOVEM","IS"},
                                        {"06","COMP","IS"},
                                        {"07","BC","IS"},
                                        {"08","DIV","IS"},
                                        {"09","READ","IS"},
                                        {"10","PRINT","IS"} };
    
    public boolean checkOp(String checkme) throws NumberFormatException {
        int count = 0;
        while(count != 11) {
            if(opcodeTable[count][1].equals(checkme) ) {
                System.out.print("(" + opcodeTable[count][2] + " " + opcodeTable[count][0] + ")");
                return true;
            }   

            count++;
        }
        return false;
    }
} 

public class Register {
    private String registerTable[][] = { {"1","AREG"},  
                                        {"2","BREG"},
                                        {"3","CREG"},
                                        {"4","DREG"}
                                       };
    public boolean checkReg(String checkme) throws NumberFormatException{
        int count = 0;
        while(count != 11) {
            if(registerTable[count][1].equals(checkme)) {
                System.out.print("(" + registerTable[count][0] + ")");
                return true;
            }   

            count++;
        }
        return false;
    }   
} 


public class Operations {
    private String operaTable[][] = { {"1","LT"},  
                                        {"2","LE"},
                                        {"3","EQ"},
                                        {"4","GT"},
                                        {"5","GE"},
                                        {"6","ANY"},
                                       };
    public boolean checkopera(String checkme) throws NumberFormatException {
        int count = 0;
        while(count != 11) {
            if(operaTable[count][1].equals(checkme)) {
                System.out.print("(" + operaTable[count][0] + ")");
                return true;
            }   

            count++;
        }
        return false;
    }   
} 

public class Symbol { 
    private int symCount = 1;
    private String symTable[][] = new String[10][3];

    public boolean checkSymbol(String checkme,int line) throws NumberFormatException {
        int count = 1;
        while(count != symCount) {
            if(symTable[count - 1][1].equals(checkme)) 
            {
                if(line == 3)
                    System.out.print("(S, 0" + symTable[count - 1][0] + ")");
                
                return true;
            }   
            count++;
        }
        return false;
    }

    public void setSymbol(String setThis) throws NumberFormatException {
        symTable[symCount-1][0] = String.valueOf(symCount);
        symTable[symCount-1][1] = setThis;
        symCount++;
    }

    public int setSymbolret(String setThis) throws NumberFormatException {
        symTable[symCount-1][0] = String.valueOf(symCount);
        symTable[symCount-1][1] = setThis;
        symCount++;
        return symCount - 1;
    }
}

public class Literal { 
    private int litCount = 1;
    private String litTable[][] = new String[10][3];

    public boolean checkLit(String checkme) throws NumberFormatException{
        int count = 1;
        while(count != litCount) {
            if(litTable[count - 1][1].equals(checkme) ) 
            {
                System.out.print("(L, 0" + litTable[count - 1][0] + ")");
                return true;
            }   
            count++;
        }
        return false;
    }


    public void setLiteral(char setThis) throws NumberFormatException {
        litTable[litCount-1][0] = String.valueOf(litCount);
        litTable[litCount-1][1] = String.valueOf(setThis);
        System.out.print("(L, 0" + litTable[litCount - 1][0] + ")");
        litCount++;
    }
}

// public class Pool { 
//     private int poolCount = 1;
//     private String poolTable[][] = new int[10][2];
// }


