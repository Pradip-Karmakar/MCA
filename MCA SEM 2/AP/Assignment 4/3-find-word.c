/*********************************************************************************************

Name : Pradip . S . Karmakar
Roll-No : 10
Class : MCA-2
Subject : Advanced Programming

**********************************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()

{
    int i = 0, length = 0, count = 0, finding = 0, first_occurance = 0;
    char search_this_word[50], search;
    char c;
    FILE *f = fopen ("readlinebyline.txt", "r"); 

    printf("Enter the word you want to search: ");
    scanf("%s", search_this_word);

    length = strlen (search_this_word);

    if (f) {
        if(!length) {
            exit(0);
        }

        search = search_this_word[0];

        while((c = fgetc(f)) != EOF){
            if (count == 0) {
                first_occurance++;
            }

            if (search == c) {
                finding = 1;

                if(length == i + 1) {

                    i = finding = 0;
                    count++;
                    search = search_this_word[i];
                }

                else {
                    search = search_this_word[++i];
                }

            }
            else {
                finding = 0;
            }
        }

        if (count > 0) {
            printf ("\"%s\" found 1st time at %d position \n", search_this_word, first_occurance - length + 1);
            printf ("\"%s\" found %d times\n", search_this_word, count);
        }
        else {
            printf ("\"%s\" not found\n", search_this_word);
        }
    }
    else {
        puts ("Cannot open file to read");
    } 
    printf ("\n");
}


 * Data in file :

    Pradip karmakar

 * Output :


    Enter the word you want to search: kar
    "kar" found 1st time at 8 position 
    "kar" found 2 times

**********************************************************************************************