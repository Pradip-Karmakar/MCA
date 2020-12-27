import java.util.StringTokenizer;

public class assembler
{
    static String[][] symbolTable=new String[10][2] ;//this is symbol table
    static String[][] litTable=new String[10][2] ;//this is literal table
    static int[] poolTable= new int[10];//this is literal table
    static int locationCounter =0;
    static int poolTabPtr = 0;//pooltable pointer
    static int litTabPtr = 0;//literaltable pointer
	static int symbolTabPtr=0;
    
   public static void main(String[] args)
   {
        poolTable[0]=1;
        String statements = "START 200\nREAD A\nREAD B\nMOVER AREG,A\nADD AREG,B\nMOVEM AREG,RESULT\nPRINT A\nPRINT B\nPRINT RESULT\nA DS 0\nB DS 1\nRESULT DS 0\nEND";
	
        String delimiters = "[, \n\t]";	//comma,space,new line, tab are delimiters
        String[] tokens = statements.split(delimiters, 0);																				
        String code;
        String regNO;
        int size=0;
        int i=0;
        for(i=0;i<tokens.length;i++)
        {
			int index=0;
            String token = tokens[i];
            String result = mnemonic(token,"type");//to find type
			code = mnemonic(token,"code");//to find code

            if(result.equals("AD"))
            {
	
                if(token.equals("START"))
                {
                    locationCounter = Integer.parseInt(tokens[i+1]);//to go to next token
                    System.out.println("LC= "+locationCounter);
                    i++;
                }
                else if(token.equals("EQU"))
                {
                    index = get_symbol_index(tokens[i+1]);//for finding address of loop
					System.out.println("IC=(AD,"+code+") (S,"+index+1+")");
                    String address = symbolTable[index][1];
                    index = get_symbol_index(tokens[i-1]);//for finding address of equ
                    symbolTable[index][1] = address;
                    i++;
					
                }
                else if(token.equals("ORIGIN"))
                {
                    index = get_symbol_index(tokens[i+1]);//for finding address of loop
                    int address = Integer.parseInt(symbolTable[index][1]);
						
                     if((tokens[i+2].substring(0)).equals("+"))
                        locationCounter = address + Integer.parseInt(tokens[i+2].substring(1,(tokens[i+2].length()-1)));
                    if((tokens[i+2].substring(0)).equals("-"))
                        locationCounter = address - Integer.parseInt(tokens[i+2].substring(1,(tokens[i+2].length()-1)));

                    i+=2;
                  System.out.println("IC=(AD,"+code+") (C,"+locationCounter+")");
                }
                else if(token.equals("LTORG") || (token.equals("END") && i < tokens.length))
                {
             
                    for(index = poolTable[poolTabPtr]-1;index<litTabPtr;index++)
                    {
                        litTable[index][1] = String.valueOf(locationCounter);
						System.out.println("IC=(AD,"+litTable[index][0]+") (C,"+locationCounter+")");
                        locationCounter++;
                    }
					
					poolTabPtr++;
					poolTable[poolTabPtr] = litTabPtr+1;
					
                }
				
				
            }
            else if(result == "" && !isliteral(token))//for label
            {
				index=get_symbol_index(token);
				
                if(mnemonic(tokens[i+1],"type").equals("IS"))
                {
					if(index== -1)	//labal is not inserted in symolTable
					{
						symbolTable[symbolTabPtr][0] = token;
						symbolTable[symbolTabPtr][1] = String.valueOf(locationCounter);//to insert lc in symbol table
						symbolTabPtr++;
					}
					else
					{
						symbolTable[index][1]=String.valueOf(locationCounter);
					}
                }
            }
            else if(result.equals("IS"))
            {
				
				regNO= mnemonic(tokens[i+1],"code");//to find register number eg.1 for AREG
                locationCounter++;
                String operand = tokens[i+2];
				if(token.equals("STOP"))	//if stop condition
					System.out.println("IC=(IS,00)");
				
				else
				{
					if(!isliteral(operand))
					{
						if(get_symbol_index(operand) == -1)		//if symbol is not in symtab
						{
							symbolTable[symbolTabPtr][0] = operand;
							symbolTabPtr++;
							System.out.println("IC=(IS,"+code+") ("+regNO+") (S, "+symbolTabPtr+")");
						}
						else	//if symbol is present in symTab
						{
							index = get_symbol_index(operand)+1;
							System.out.println("IC=(IS,"+code+") ("+regNO+") (S, "+index+")");
						}
					
					}
				
					else//if operand is litral
					{	
						String this_litral=operand.substring(2,(operand.length()-1));
						litTable[litTabPtr][0]=String.valueOf(this_litral);

						litTabPtr++;
						System.out.println("IC=(IS,"+code+") ("+regNO+") (L, "+litTabPtr+")");
					}
					i+=2; 
				}
			}
            else if(result.equals("DL"))
            {
			
                index = get_symbol_index(tokens[i-1]);
                code = mnemonic(token,"code");
                size = Integer.parseInt(tokens[i+1]);
                symbolTable[index][1]=String.valueOf(locationCounter);
                System.out.println("IC=(DL,"+code+") (C, "+(index+1)+")");
                locationCounter+=size;
                
                i++;
            }
            
        }
        System.out.println("\n------------->Literal Table");
        for(int index=0;index<litTabPtr;index++)
        {
           System.out.println(litTable[index][0]+ ":"+litTable[index][1]);
        }
        System.out.println("\n------------->Symbol Table");
        for(int index=1;index<symbolTabPtr-1;index++) //for testing values of symbol table
        {
            System.out.println(symbolTable[index][0] + " - " + symbolTable[index][1]);
        }
            System.out.println("\n------------->Pool Table");
            for(int index=0;index<=poolTabPtr;index++)
            {
                System.out.println(poolTable[index]);
            }
   }

   public static String mnemonic(String token,String want)
   {
        String[][] codes = {{"00","STOP","IS"},{"01","ADD","IS"},{"02","SUB","IS"},{"03","MULT","IS"},{"04","MOVER","IS"},{"05","MOVEM","IS"},
                        {"06","COMP","IS"},{"07","BC","IS"},{"08","DIV","IS"},{"09","READ","IS"},{"10","PRINT","IS"},
                        {"01","DC","DL"},{"02","DS","DL"},{"01","START","AD"},{"02","END","AD"},{"03","ORIGIN","AD"},{"04","EQU","AD"},
                    {"05","LTORG","AD"},{"1","AREG","REG"},{"2","BREG","REG"},{"3","CREG","REG"},{"4","DREG","REG"},
                    {"1","LT","FLAG"},{"2","LE","FLAG"},{"3","EQ","FLAG"},{"4","GT","FLAG"},{"5","GE","FLAG"},
                    {"6","ANY","FLAG"}};
        for(String[] code : codes)	//to return type or code of token
        {
            if(token.equals(code[1]))
            {
                if(want.equals("type"))
                    return code[2];
                if(want.equals("code"))
                    return code[0];
            }
        }
        return "";
   }
   //to find literals
   public static boolean isliteral(String token)
   {
       if(token.startsWith("=") || token.startsWith("\'"))
       {
           return true;
       }
       return false;
   }

   //tocheck already exist
   public static int get_symbol_index(String token)
   {
        int index;
        for(index=0;index<symbolTabPtr;index++)
        {
            if(symbolTable[index][0].equals(token))
            {
                return index;
            }
        }
        
		
       return -1;
   }
}