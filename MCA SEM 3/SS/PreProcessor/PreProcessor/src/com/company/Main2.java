// package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main2 {

    public static void main(String[] args) throws IOException {

        List<String> code = new ArrayList<>();

        code.add("\tMACRO");
        code.add("\tCLEARMEM &X, &N, &REG=AREG");
        code.add("\tLCL &M");
        code.add("\t&M SET 0");
        code.add("\tMOVER &REG, ='0'");
        code.add(".MORE MOVEM &REG, &X + &M");
        code.add("\t&M SET &M+1");
        code.add("\tAIF (&M NE &N) .MORE");
        code.add("\tMEND");
        code.add("\tMMEND");

        System.out.println("Starting Preprocessing...");

        PreProcessor pr = new PreProcessor(code);

        pr.showCode();
        pr.analyze();
        pr.showTables();

        System.out.println("Ending Preprocessing...");
    }
}


class MacroData {
    String name;
    int pp, kp, ev, mdtp, kpdtp, sstp;

    MacroData() {
        name = "";
        pp = kp = ev = mdtp = kpdtp = sstp = 0;
    }
}

class PreProcessor {
    private List<String> code;

    private List<String> pntab;
    private List<String> evntab;
    private List<String> ssntab;
    private List<MacroData> mnt;
    private List<String[]> kpdtab;
    private List<Integer[]> sstab;
    private List<String> mdt;

    private int pntab_ptr;
    private int evntab_ptr;
    private int ssntab_ptr;
    private int mnt_ptr;
    private int kpdtab_ptr;
    private int sstab_ptr;
    private int mdt_ptr;

    public PreProcessor(String filename) throws IOException {
        initialize();
        loadCode(filename);
    }

    public PreProcessor(List<String> code) {
        initialize();
        this.code = code;
    }

    private static List<String> tokenize(String line) {
        StringTokenizer st = new StringTokenizer(line, ", \t()");
        List<String> tokenized = new ArrayList<>();

        while (st.hasMoreTokens()) {
            tokenized.add(st.nextToken());
        }

        return tokenized;
    }

    private static String getParameterType(String parameter) {
        return parameter.indexOf('=') == -1 ? "PP" : "KP";
    }

    private static boolean isSequencingSymbol(String token) {
        return token.charAt(0) == '.';
    }

    private void initialize() {
        pntab = new ArrayList<>();
        evntab = new ArrayList<>();
        ssntab = new ArrayList<>();
        mnt = new ArrayList<>();
        kpdtab = new ArrayList<>();
        sstab = new ArrayList<>();
        mdt = new ArrayList<>();

        pntab_ptr = evntab_ptr = ssntab_ptr = mnt_ptr =
                kpdtab_ptr = sstab_ptr = mdt_ptr = 0;
    }

    private String getIC(String data) {
        String ic = "(%s,%s)";
        int index = -1;
        int start = data.charAt(0) == '&' || data.charAt(0) == '.' ? 1 : 0;
        data = data.substring(start).toUpperCase();

        for(int i = 0; i < evntab_ptr && index == -1; i++) {
            if(evntab.get(i).toUpperCase().equals(data)) index = i;
        }
        if(index != -1) return String.format(ic, "E", ("" + index));

        for(int i = 0; i < pntab_ptr && index == -1; i++) {
            if(pntab.get(i).toUpperCase().equals(data)) index = i;
        }
        if(index != -1) return String.format(ic, "P", ("" + index));

        for(int i = 0; i < ssntab_ptr && index == -1; i++) {
            if(ssntab.get(i).toUpperCase().equals(data)) index = i;
        }
        if(index != -1) return String.format(ic, "S", ("" + index));

        return null;
    }

    private static String removeSequencingSymbol(String line) {
        line = line.trim();
        if(line.charAt(0) == '.') {
            int indexOfSpace = line.indexOf(' ');
            line = line.substring(indexOfSpace + 1);
        }
        return line;
    }

    private String getLineIC(String line) {
        String lineIC = removeSequencingSymbol(line);
        List<String> tokenized = tokenize(lineIC);

        for(int i = 0; i < tokenized.size(); i++) {
            String ic = getIC(tokenized.get(i));

            if(ic != null) {
                lineIC = lineIC.replaceAll(tokenized.get(i), ic);
            }
        }
        return lineIC;
    }

    private void loadCode(String filename) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        code = new ArrayList<>();

        String line;

        while ((line = reader.readLine()) != null) {
            code.add(line);
        }

        if (reader != null) reader.close();
    }

    public void showCode() {
        for (int i = 0; i < code.size(); i++) {
            System.out.println(code.get(i));
        }
    }

    public void showTables() {
        System.out.println("\n------- TABLES -------\n");

        System.out.println("-------------------- MNT --------------------");
        System.out.println("MACRONAME\t#PP\t#KP\t#EV\tMDTP\tKPDTP\tSSTP");
        System.out.println("---------------------------------------------");
        for (int i = 0; i < mnt_ptr; i++) {
            MacroData md = mnt.get(i);
            System.out.println(md.name + "\t" + md.pp + "\t" + md.kp + "\t" + md.ev + "\t" + md.mdtp + "\t\t" + md.kpdtp + "\t\t" + md.sstp);
        }
        System.out.println("---------------------------------------------");


        System.out.println("\n----- PNTAB -----");
        System.out.println("Index\tName");
        System.out.println("-----------------");
        for (int i = 0; i < pntab_ptr; i++) {
            System.out.println(i + "\t\t" + pntab.get(i));
        }
        System.out.println("-----------------");

        System.out.println("\n----- EVNTAB -----");
        System.out.println("Index\tName");
        System.out.println("------------------");
        for (int i = 0; i < evntab_ptr; i++) {
            System.out.println(i + "\t\t" + evntab.get(i));
        }
        System.out.println("------------------");

        System.out.println("\n----- SSNTAB -----");
        System.out.println("Index\tName");
        System.out.println("------------------");
        for (int i = 0; i < ssntab_ptr; i++) {
            System.out.println(i + "\t\t" + ssntab.get(i));
        }
        System.out.println("------------------");

        System.out.println("\n---------- SSTAB ----------");
        System.out.println("Index\tValue\tValue");
        System.out.println("---------------------------");
        for (int i = 0; i < sstab_ptr; i++) {
            System.out.println(i + "\t\t" + sstab.get(i)[0] + "\t\t" +sstab.get(i)[1]);
        }
        System.out.println("---------------------------");

        System.out.println("\n-------- KPDTAB --------");
        System.out.println("Index\tName\tDefault");
        System.out.println("------------------------");
        for (int i = 0; i < kpdtab_ptr; i++) {
            System.out.println(i + "\t\t" + kpdtab.get(i)[0] + "\t\t" + kpdtab.get(i)[1]);
        }
        System.out.println("------------------------");

        System.out.println("\n-------------------------- MDT --------------------------");
        System.out.println("Index\tIC");
        System.out.println("---------------------------------------------------------");
        for (int i = 0; i < mdt_ptr; i++) {
            System.out.println(i + "\t\t" + mdt.get(i));
        }
        System.out.println("---------------------------------------------------------");
    }

    public void analyze() {

        List<String> tokenized;
        MacroData md = new MacroData();

        // MACRO PROTOTYPE PROCESSING STARTS HERE
        String prototype = code.get(1);
        tokenized = tokenize(prototype);

        md.name = tokenized.get(0);
        md.kpdtp = kpdtab_ptr;

        for (int i = 1; i < tokenized.size(); i++) {
            String parameter = tokenized.get(i);
            if (getParameterType(parameter).equals("PP")) {
                System.out.println(parameter + " is PP");
                pntab.add(parameter.substring(1));
                pntab_ptr++;
                md.pp++;
            } else {
                System.out.println(parameter + " is KP");
                int index = parameter.indexOf('=');
                String parameterName = parameter.substring(1, index);
                String defaultValue = parameter.substring(index + 1);
                String[] kpdtab_entry = {parameterName, defaultValue};

                kpdtab.add(kpdtab_entry);
                pntab.add(parameterName);

                kpdtab_ptr++;
                pntab_ptr++;
                md.kp++;
            }
        }

        md.mdtp = mdt_ptr;
        md.ev = 0;
        md.sstp = sstab_ptr;

        // MACRO PROTOTYPE PROCESSING ENDS HERE

        // MACRO MODEL STATEMENTS PROCESSING STARTS HERE

        for (int i = 2; i < code.size(); i++) {
            String currentLine = code.get(i);
            tokenized = tokenize(currentLine);

            if(tokenized.size() < 1) continue;

            boolean hasSequencingSymbol = isSequencingSymbol(tokenized.get(0));

            if(hasSequencingSymbol) {
                ssntab.add(tokenized.get(0).substring(1));
                int index = ssntab_ptr++;

                Integer[] data = {index, mdt_ptr};
                sstab.add(data);
            }

            System.out.println("CurrentLine: " + currentLine);
            if (tokenized.get(0).toUpperCase().equals("LCL")) {
                int start = tokenized.get(1).charAt(0) == '&' ? 1 : 0;
                String variable = tokenized.get(1).substring(start);
                evntab.add(variable);
                evntab_ptr++;
                md.ev++;

                String lineIC = getLineIC(currentLine);
                System.out.print(lineIC);
                mdt.add(lineIC);
                mdt_ptr++;
            }
            else if(tokenized.size() > 1 && tokenized.get(1).toUpperCase().equals("SET")) {
                String lineIC = getLineIC(currentLine);
                System.out.println("IC-> "+lineIC);
                mdt.add(lineIC);
                mdt_ptr++;
            }
            else if(tokenized.get(0).toUpperCase().equals("AIF") || tokenized.get(0).toUpperCase().equals("AGO")) {
                String sequencingSymbol = tokenized.get(tokenized.size() - 1).substring(1);

                int index = ssntab.indexOf(sequencingSymbol);

                if(index == -1) {
                    ssntab.add(sequencingSymbol);
                    index = ssntab_ptr++;
                }

                String lineIC = getLineIC(currentLine);
                System.out.println(lineIC);
                mdt.add(lineIC);
                mdt_ptr++;
            }
            else if (tokenized.get(0).toUpperCase().equals("MEND")) {
                if(ssntab_ptr == 0) md.sstp = 0;
                else sstab_ptr = sstab_ptr + ssntab_ptr;
                break;
            }
            else {
                String lineIC = getLineIC(currentLine);
                System.out.print(lineIC);
                mdt.add(lineIC);
                mdt_ptr++;
            }
        }

        // MACRO MODEL STATEMENTS PROCESSING ENDS HERE

        mnt.add(md);
        mnt_ptr++;
    }

}
