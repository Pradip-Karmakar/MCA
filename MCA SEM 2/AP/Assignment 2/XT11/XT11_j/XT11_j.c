#include<stdio.h>
#include<conio.h>

void getdata(char *);
void upper(char *);

void main()
{
    char string[10],*ptrstr;
    ptrstr = string;
    getdata(ptrstr);
    upper(ptrstr);
}

void getdata(char *s)
{
    printf("\nEnter the string : ");
    scanf("%s",s);
}

void upper(char *s)
{
    char *temp;
    temp = s;
    while( *s != '\0' )
    {
        if( *s > 96 && *s < 123 )
        {
            *s -= 32;
        }
        s++;
    }
    printf("\n%s",temp);
}
