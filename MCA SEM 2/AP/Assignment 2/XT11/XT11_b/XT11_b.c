#include<stdio.h>
#include<conio.h>

void getstring(char *);
int checksubset(char *,char *);
void print(int);

void main()
{
    int index;
    char mainstr[15], str[10], *mainptr, *ptr;
    mainptr = mainstr;
    ptr = str;
    printf( "Enter The Main String : " );
    getstring(mainstr);
    printf( "Enter The Sub String : " );
    getstring(ptr);
    index = checksubset(mainptr,ptr);
    print(index);
}

void getstring(char *ptr)
{
    scanf("%s",ptr);
}

int checksubset(char *main,char *sub)
{
    int flag = 0, index = 0, subindex = 0, returnvalue = 404;
    char *temp;
    temp = sub;
    while( *main != '\0' && flag != 1 )
    {
        if( *main == *sub )
        {
            index++;
            sub++;
            main++;
            subindex++;
            if(*sub == '\0')
            {
                flag = 1;
                returnvalue = index - subindex;
            }            
        }
        else if( *main != *sub )
        {
            index++;
            main++;
            subindex = 0;
            sub = temp;
        }
    }
    return returnvalue;
}

void print(int n)
{
    if(n != 404)
    {
        printf( "\nString Found At Index : %d" ,n);
    }
    else
    {
        printf( "\nSubstring Not Found\n" );
    }
}