public class MacroAssembler {
    public static class Operations {
        private String MNT[][] = {{"Name","#PP","#KP","#EV","MDTP","KPDTP","SSTP"},{}};
        private String KPDTAB[][];
        private String PNTAB[];
        private String EVNTAB[]; 
        private String SSNTAB[];
        private String SNTAB[];
        private String MDT[];
        
        public void MntTable(String name) {
            MNT[1][0] = name;
        }

        public void MntTable(int counter,int position) {
            MNT[1][position] = String.valueOf(counter);
        }

        public void KpdTab(String keyword, String value, int kpdtab_ptr) {
            KPDTAB[kpdtab_ptr-1][0] = keyword;
            KPDTAB[kpdtab_ptr-1][1] = String.valueOf(value);
        }

        public void PnTab(String keyword, int pntab_ptr) {
            PNTAB[pntab_ptr-1] = keyword;
        }

        public void EvnTab(String keyword, int evntab_ptr) {
            EVNTAB[evntab_ptr-1] = keyword;
        }

        public void Edt(String keyword, int mdt_ptr) {
            EVNTAB[mdt_ptr-1] += keyword;
        }
    }
    
    public static void main(String[] args) {
        Operations op = new Operations();
        String que[] = {"MACRO","CLEARMEM &X,&N,&REG=AREG","LCL &M","&M SET 0","MOVER &REG, ='0'",".MORE MOVEM &REG, &X+&M","&M SET &M+1","AIF (&M NE  N) .MORE","MEND"}; 
        int i = 1,token_ptr = 0;            
        int KPDTAB_ptr = 1, SSTAB_ptr = 1, MDT_ptr = 1, SSNTAB_ptr = 1, PNTAB_ptr = 1, EVNTAB_ptr = 1,pp = 0, kp = 0, ev = 0;
        String delimeter = "[, ]";
        String innerDeli = "[&=]";
        String[] token = que[i].split(delimeter,0);
        op.MntTable(token[token_ptr]);
        token_ptr++;
        op.MntTable(KPDTAB_ptr, 5);

        while(!token[token_ptr].equals("\0")) {
            String[] token2 = token[token_ptr].split(innerDeli,0);
            if(token[token_ptr].contains("=")) {
                op.KpdTab(token2[1], token2[2], KPDTAB_ptr);
                op.PnTab(token2[1], PNTAB_ptr);
                KPDTAB_ptr++;
                PNTAB_ptr++;
                kp++;
            } else {
                op.PnTab(token2[1], PNTAB_ptr);
                PNTAB_ptr++;
                pp++;
            }
            token_ptr++;
        }

        op.MntTable(MDT_ptr, 4);
        op.MntTable(SSTAB_ptr, 6);
        i++;
        
        while(!que[i].equals("MEND")) {
            token_ptr = 0;
            token = que[i].split(delimeter,0);
            if(token[token_ptr].contains("LCL")) {
                op.Edt(token[token_ptr],MDT_ptr);
                token_ptr++;
                while(!token[token_ptr].equals("\0")) {
                    String[] token2 = token[2].split(innerDeli,0);
                    op.EvnTab(token2[1], EVNTAB_ptr);
                    ev++;
                }

            }
        }
        // op.MntTable(token[0]);


        // while(){    

        //     //
            
        //     //

        //     // System.out.println(que[i]);
        //     // i++;
        // }
    }
}
