/*********************************************************************************************

Name : Pradip . S . Karmakar
Roll-No : 10
Class : MCA-2
Subject : Advanced Programming

**********************************************************************************************

#include <stdio.h>

void main()
{
    int a = 1;

    char mystring[50];
    char *cptr; 

    FILE *f1 = fopen("alternate.txt", "w"); 

    if(f1) {
        printf ("Enter a string : ");
        scanf  ("%s",mystring);

        cptr = mystring;
        while(*cptr != '\0') {
            if(a) {
                fprintf(f1, "%c", *cptr);
                printf("%c", *cptr);
                a = 0;
            } else {
                a = 1;
            }
            cptr++;
        }
        fclose (f1);
    }

    else {
        printf("Unable to open file");
    }

    printf("\n");
}


Output :
 
Enter a string : Pradip 
Pai

**********************************************************************************************