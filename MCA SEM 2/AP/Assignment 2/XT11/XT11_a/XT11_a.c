#include<stdio.h>
#include<conio.h>

void getstring(char *);
char finding();
int occurance(char *,char);
void print(int);

void main()
{
    char str[15],*ptr,findme;
    int index = 0;
    ptr = str;
    getstring(ptr);
    findme = finding();
    index = occurance(ptr,findme);
    print(index);
}

void getstring(char *ptr)
{
    printf("Enter the String : ");
    scanf("%s",ptr);
}

char finding()
{
    char s;
    printf("Enter The Character You Want Find : ");
    scanf(" %c",&s);
    return s;
}


int occurance(char *ptr,char s)
{
    int index = 0,flag = 0;
    while(*ptr != '\0' && flag != 1)
    {
        if( *ptr == s )
        {
            flag = 1;
        }
        else
        {
            index++;
            ptr++;
        }
    }
    if( flag == 1 )
    {
        return index;
    }
    else
    {
        return index = 101;
    }
}

void print(int index)
{
    if (index == 101)
    {
        printf("No Match Found");
    }
    else
    {
        printf("Found At Index : %d",index);    
    }
}