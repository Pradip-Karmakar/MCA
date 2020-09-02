#include<stdio.h>
#include<conio.h>

void getstring(char *);
int comparestring(char *,char *);

void main()
{
    char string1[20],string2[20],*ptrstr1,*ptrstr2;
    int rtnvalue = 0;
    ptrstr1 = string1;
    ptrstr2 = string2;
    printf("Enter The First String : ");
    getstring(ptrstr1);
    printf("Enter The Second String : ");
    getstring(ptrstr2);
    rtnvalue = comparestring(ptrstr1,ptrstr2);
    printf("\n%d",rtnvalue);
}

void getstring(char *s)
{
    scanf("%s",s);
}

int comparestring(char *s1,char *s2)
{
    int value = 0;
    while( value == 0 && (*s1 != '\0' || *s2 != '\0') )
    {
        if( *s1 > *s2 )
        {
            value = 1;
        }
        else if( *s1 < *s2 )
        {
            value = -1;
        }
        s1++;
        s2++;
    }
    return value;
}