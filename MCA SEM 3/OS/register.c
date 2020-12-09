#include<stdio.h>
#include<conio.h>
void main(){
    int a = 1,b = 2;
    register int c = 3;
    printf("Address of a is %p \n Address of b is %p \n Address of c is %p \n",&a,&b,&c);
    getch();
}