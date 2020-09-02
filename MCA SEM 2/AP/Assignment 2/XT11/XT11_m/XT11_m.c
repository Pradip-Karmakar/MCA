#include<stdio.h>
#include<conio.h>

void getstr(char *);
void append(char *,char *);

void main()
{
    char string1[20], string2[10],*ptrstr1, *ptrstr2;
    ptrstr1 = string1;
    ptrstr2 = string2;
    printf("\nEnter The Main String : ");
    getstr(ptrstr1);
    printf("\nEnter The String to be Append : ");
    getstr(ptrstr2);
    append(ptrstr1,ptrstr2);

}

void getstr(char *s)
{
    scanf("%s",s);
}

void append(char *s1,char *s2)
{
    char *temp;
    temp = s1; 
    while( *s1 != '\0' )
    {
        s1++;
    }

    while( *s2 != '\0' )
    {
        *s1 = *s2;
        s2++;
        s1++;
    }
    printf("\n %s",temp);
}