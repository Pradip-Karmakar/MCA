public class MacTry {
    public static void main(String[] args){
        String que[] = {"MACRO","CLEARMEM &X,&N,&REG=AREG","LCL &M","&M SET 0","MOVER &REG, ='0'",".MORE MOVEM &REG, &X+&M","&M SET &M+1","AIF (&M NE  N) .MORE","MEND"}; 
        String delimeter = "[, ]";
        String[] token = que[1].split(delimeter,0);
        Boolean bool = token[1].contains("=");
        System.out.println(bool);
        String innerDeli = "[&=]";
        String[] token2 = token[3].split(innerDeli,0);
        System.out.println(token2[0]);
        System.out.println(token2[1]);
        System.out.println(token2[2]);
    }
}
