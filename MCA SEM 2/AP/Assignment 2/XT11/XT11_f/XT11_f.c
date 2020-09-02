#include<stdio.h>
#include<conio.h>
#include<string.h>

void getstring(char *);
int getlenstr2(char *);
void stringremover(char *, char *,int);
char upper(char);
char lower(char);

void main()
{
    int length = 0;
    char string1[20],string2[10],*strptr1,*strptr2;
    strptr1 = string1;
    strptr2 = string2;
    printf("Enter The First String : ");
    getstring(strptr1);
    printf("Enter The Second String : ");
    getstring(strptr2);
    length = getlenstr2(strptr2);
    stringremover(strptr1,strptr2,length);

}

void getstring(char *string)
{
    scanf("%s",string);
}

int getlenstr2(char *s2)
{
    int count = 0;
    while( *s2 != '\0' )
    {
        ++count;
        s2++;
    }
    return count;
}

void stringremover(char *s1, char *s2, int length_s2)
{
    int flag = 0;
    char *string1,*string2,*temp;
    temp = s1;
    string2 = s2;
    while( *s1 != '\0' && flag != 1 )
    {
        if( *s1 == *s2 || *s1 == (*s2 + 32) || *s1 == (*s2 - 32) )
        {
            string1 = s1;
            while( *string2 != '\0' && (*string1 == *string2 || *string1 == (*string2 + 32) || *string1 == (*string2 - 32) ) )
            {
                string2++;
                string1++;
            }
            if( *string2 == '\0'  )
            {
                string2 = s2;
                while( *s1 != '\0')
                {
                    *s1 = *(s1 + length_s2);
                    s1++;
                }
                s1 = temp;
            }
            else
            {
                string2 = s2;
            }
        }
        s1++;
    }
    printf("%s",temp);
}