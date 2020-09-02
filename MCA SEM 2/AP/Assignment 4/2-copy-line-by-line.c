/*********************************************************************************************

Name : Pradip . S . Karmakar
Roll-No : 10
Class : MCA-2
Subject : Advanced Programming

********************************************************************************************** 
 
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int no_of_lines = 0;
    char line[1000];
    FILE *f1 = fopen("read.txt", "r");
    FILE *f2 = fopen("newread.txt", "w");
    if(f1 && f2) {
		if (fgetc(f1) == EOF) {
			printf ("No data found\n");
		    exit(0);
        } 

        while(fgets(line, sizeof line, f1)) {
            no_of_lines++;
            // fputs (line, stdout);
            fputs (line, f2);
        }
         
        printf("\n%d lines yanked and pasted", no_of_lines);

        fclose(f1);
        fclose(f2);

    }

    else {
        ferror(f1);
        ferror(f2);
    }
    puts ("\n");
}

 
Output :
 
    5 lines yanked and pasted

**********************************************************************************************
