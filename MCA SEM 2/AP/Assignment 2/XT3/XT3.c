#include<stdio.h>
#include<conio.h>
#include<string.h>

void filterString(char[]);

void main()
{
    char string1[50];
    printf("Enter String : ");
    scanf("%[^\n]",string1);
    filterString(string1);
    printf("\n");
}


void filterString(char string1[])
{
    char *cptr;
    int Vowels = 0, Consonants = 0, Numbers = 0, Whitespaces = 0, Special_Characters = 0;
    cptr = string1;
    while(*cptr != '\0') {
        if(*cptr == 65 || *cptr == 69 || *cptr == 73 || *cptr == 79 || *cptr == 85 || *cptr == 97 || *cptr == 101 || *cptr == 105 || *cptr == 111 || *cptr == 117) {
            Vowels++;
        }
        else if (*cptr > 47 && *cptr < 58) {
            Numbers++;
        }
        else if(*cptr == 9 || *cptr == 32) {
            Whitespaces++;
        }
        else if((*cptr > 64 && *cptr < 91) || (*cptr > 96 && *cptr < 123)){
            Consonants++;
        }
        else {
            Special_Characters++;
        }
    cptr++;
    }
    printf("\n Vowels: %d\n", Vowels);
    printf("\n Numbers: %d\n", Numbers);
    printf("\n Whitespaces: %d\n", Whitespaces);
    printf("\n Consonants: %d\n", Consonants);
    printf("\n Special Characters: %d\n", Special_Characters);
}