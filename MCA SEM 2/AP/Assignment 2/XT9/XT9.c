#include<stdio.h>
#include<conio.h>

void getinput(float *);
int getdecimal();
void print(float *,int);

void main()
{
    int decimal = 0;
    float num,*ptr;
    ptr = &num;
    getinput(ptr);
    decimal = getdecimal();
    print(ptr,decimal);
    getch();
}

void getinput(float *ptr)
{
    printf("Enter The Decimal Number : ");
    scanf("%f",ptr);
}

int getdecimal()
{
    int i = 0;
    printf("Enter How Many Decimal Point You Want : ");
    scanf("%d",&i);
    return i;
}

void print(float *ptr,int i)
{
    printf("%.*f",i,*ptr);
}