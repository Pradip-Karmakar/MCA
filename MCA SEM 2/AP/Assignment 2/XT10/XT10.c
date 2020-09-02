#include<stdio.h>
#include<conio.h>

void getnumber(int *);
void exchange(int *, int *);
void print(int *);
void main()
{
    int a,*ptra,b,*ptrb;
    ptra = &a;
    ptrb = &b;
    getnumber(ptra);
    getnumber(ptrb);
    printf("\nValue : %d At Address : %p",*ptra,ptra);
    printf("\nValue : %d At Address : %p\n",*ptrb,ptrb);
    exchange(ptra,ptrb);
    printf("\nAfter Exchange Values \n");
    printf("\nValue : %d At Address : %p",*ptra,ptra);
    printf("\nValue : %d At Address : %p",*ptrb,ptrb);
}

void getnumber(int *ptr)
{
    printf("\nEnter Number : ");
    scanf("%d",ptr);
}

void exchange(int *ptra, int *ptrb)
{
    *ptra = *ptra + *ptrb;
    *ptrb = *ptra - *ptrb;
    *ptra = *ptra - *ptrb;
}

void print(int *ptr)
{
    printf("%d\n",*ptr);
}