package com.company;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

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
