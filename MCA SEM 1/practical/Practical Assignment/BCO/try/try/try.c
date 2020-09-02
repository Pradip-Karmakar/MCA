#include<stdio.h>
#include<conio.h>
void main()
{
	int a = 1,b;
	/*b = a++ + a++ + ++a + ++a + --a + a++ + --a*/
	b = --(a=a--);
	printf("%d", b);
	getch();
}