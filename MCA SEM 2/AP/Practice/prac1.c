#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void getdata(char[]);
void serialcon(char[]);

void main()
{
    char s[10];
    getdata(s);
    serialcon(s);
}

void getdata(char s[])
{
    printf("Enter Your String : ");
    scanf("%s",s);
}

void serialcon(char s[])
{
    int i, j, a = 0, seri[10] = {0}, len = strlen(s);
    for( i = 0; i < len; i++ )
    {
        if( isdigit(s[i]) )
        {
            printf(" Error ");
            exit(0);
        }

        for( j = i; j >= 0; j-- )
        {
            if( s[i] == s[j] )
            {
                seri[i] = seri[j];
            }
        }
        
        if(seri[i] == 0)
        {
            seri[i] = ++a;
        }
        
    }

    for( i = 0; i < len; i++ )
    {
        printf(" %d ",seri[i]);
    }
}