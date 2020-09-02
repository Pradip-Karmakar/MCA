#include<stdio.h>
#include<conio.h>

void getstr( char * );
void reverse( char * );
int length( char * );

void main()
{
    char string[20],*ptrstr;                                                                       
    ptrstr = string;
    getstr(ptrstr);
    reverse(ptrstr);
}

void getstr( char *s )
{
    printf("Enter The String : ");
    scanf("%s",s);
}

void reverse( char *s )
{
    int leng = length(s),endlength = leng/2;
    char *tempstr, tempchar, *s1;
    tempstr = s;
    s1 = s+(leng-1);
    while( endlength > 0 )
    {
        tempchar = *s;
        *s = *s1;
        *s1  = tempchar;
        endlength--;
        s++;
        s1--;
    }
    printf("%s",tempstr);
}

int length( char *s )
{
    int len = 0;
    while( *s != '\0' )
    {
        len++;
        s++;
    }
    return len;
}