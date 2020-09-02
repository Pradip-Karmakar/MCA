#include<stdio.h>
#include<conio.h>

void getstring(char *);
int getnvalue();
int comparestring(char *,char *,int);

void main()
{
    char string1[20],string2[20],*ptrstr1,*ptrstr2;
    int rtnvalue = 0, n = 0;
    ptrstr1 = string1;
    ptrstr2 = string2;
    printf("Enter The First String : ");
    getstring(ptrstr1);
    printf("Enter The Second String : ");
    getstring(ptrstr2);
    n = getnvalue();
    rtnvalue = comparestring(ptrstr1,ptrstr2,n);
    printf("\n%d",rtnvalue);
}

void getstring(char *s)
{
    scanf("%s",s);
}

int getnvalue()
{
    int i;
    printf("Enter the Limit for Comparing : ");
    scanf("%d",&i);
    return i;
}

int comparestring(char *s1,char *s2, int i)
{
    int value = 0;
    while( value == 0 && (*s1 != '\0' || *s2 != '\0') && i > 0 )
    {
        if( *s1 > 64 && *s1 < 91 )
        {
            *s1 += 32;
        }
        if( *s2 > 64 && *s2 < 91 )
        {
            *s2 += 32;
        }
        if( *s1 > * s2 )
        {
            value = 1;
        }
        else if( *s1 < *s2 )
        {
            value = -1;
        }
        s1++;
        s2++;
        i--;
    }
    return value;
}