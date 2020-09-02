#include<conio.h>
#include<stdio.h>

void getstring(char *);
int getlength(char *);
void toggle(char *);

void main()
{
    char string[20],*ptrstr;
    int length = 0;
    ptrstr = string;
    getstring(ptrstr);
    length = getlength(ptrstr);
    printf("Length of The String Is : %d\n",length);
    toggle(ptrstr); 
}

void getstring(char *s)
{
    printf("\nEnter The String : ");
    scanf("%s",s);
}

int getlength(char *s)
{
    int i = 0;
    while( *s != '\0' )
    {
        s++;
        i++;
    }
    return i;
}

void toggle(char *s)
{
    char *temp;
    temp = s;
    while( *s != '\0' )
    {
        if( *s > 64 && *s < 91 )
        {
            *s += 32;
        }
        else if( *s > 96 && *s < 123 )
        {
            *s -= 32;
        }
        s++;
    }
    printf("\nAfter Toggle : %s",temp);
}