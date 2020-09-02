#include<stdio.h>
#include<conio.h>

void getstr(char *);
void copy(char *,char *);

void main()
{
    char string1[20], string2[10],*ptrstr1, *ptrstr2;
    ptrstr1 = string1;
    ptrstr2 = string2;
    printf("\nEnter The Main String : ");
    getstr(ptrstr1);
    printf("\nEnter The String to be Copy : ");
    getstr(ptrstr2);
    copy(ptrstr1,ptrstr2);

}

void getstr(char *s)
{
    scanf("%s",s);
}

void copy(char *s1,char *s2)
{
    char *temp;
    temp = s1; 
    while( *s2 != '\0' )
    {
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    printf("\nAfter Copy To The First String : %s",temp);
}