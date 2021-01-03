#include<stdio.h>
#include<conio.h>
int get(char str[][10], int range)
{
	int i, j;
	printf("Enter The Limit Of Strings : ");
	scanf("%d",&range);
	for( i = 0; i < range; i++ )
	{ 
		printf("Enter String In Row %d ",i+1);
		scanf("%s",str[i]);
	}
	return(range);
}
void print(char str[][10],int range)
{
	int i, j;
	for( i = 0; i < range; i++)
	{
		printf("%s\n",str[i]);
	}
}
void main()
{
	int i, j, k, range1 = 0, range2 = 0;
	char string1[10][10], string2[10][10];
	range1 = get(string1,range1);
	range2 = get(string2,range2);
	printf("String 1 before sorting\n");
	print(string1,range1);
	printf("String 2 before sorting\n");
	print(string2,range2);
	getch();
}