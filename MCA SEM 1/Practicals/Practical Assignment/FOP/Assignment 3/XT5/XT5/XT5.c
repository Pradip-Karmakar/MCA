#include<stdio.h>
#include<conio.h>
void main()
{
	int i, j, k, n = 9;
	for(i = n; i > 1; i++)
	{
		printf(" ");
	}
	for(i = 1; i <= n; i++)
	{
		for(j = n; j > i; j--)
		{
			printf(" ");
		}
		for(j = i; j <= i*2-1; j++)
		{
			if(j < 10)
			{
				printf("%d",j);
			}
			else
			{
				j -= 10;
				printf("%d",j);
				j +=10;
			}
		}
		for(k = i*2-2; k >= n; k--)
		{
			if(k < 10)
			{
				printf("%d",k);
			}
			else
			{
				k -= 10;
				printf("%d",k);
				k +=10;
			}
		}
		printf("\n");
	}
getch();
}