#include<stdio.h>
#include<conio.h>

void getstr(char *);
int getnchar();
void copy(char *,char *,int);

void main()
{
    char string1[20], string2[10],*ptrstr1, *ptrstr2;
    int limit = 0;
    ptrstr1 = string1;
    ptrstr2 = string2;
    printf("\nEnter The Main String : ");
    getstr(ptrstr1);
    printf("\nEnter The String to be Append : ");
    getstr(ptrstr2);
    limit = getnchar();
    copy(ptrstr1,ptrstr2,limit);
}

void getstr(char *s)
{
    scanf("%s",s);
}

int getnchar()
{
    int d;
    printf("How Many Char You Want to Append from String 2 : ");
    scanf("%d",&d);
    return d;
}

void copy(char *s1, char *s2, int i)
{
    char *temp;
    temp = s1; 

    while( i > 0 && *s2 != '\0')
    {
        *s1 = *s2;
        i--;
        s1++;
        s2++;
    }

    *s1 = '\0';
    printf("\n%s",temp);
}