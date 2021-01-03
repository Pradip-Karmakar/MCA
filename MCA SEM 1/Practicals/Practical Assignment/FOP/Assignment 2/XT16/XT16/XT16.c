#include<stdio.h>
#include<conio.h>
int factorial(int n)
{
	return (n==1 || n==0) ? 1: n * factorial(n - 1); 
}

void main()
{
	int i, j, k, l, max_number, limit, result[20], combination = 0; 
	printf("Enter The Max Number : ");
	scanf("%d",&max_number);
	printf("Enter The Limit Of Print Column : ");
	scanf("%d",&limit);
	l = limit-1;
	for( i = 1; i <= limit; i++ )
	{
		result[i-1] = i;
	}

	combination = (factorial(max_number)/(factorial(max_number-limit)*factorial(limit)));
	
	for( i = 0; i < combination; i++ )
	{
		for( j = 0; j < limit; j++ )
		{
			printf("%d ",result[j]);
		}
		printf("\n");
		result[j - 1]++;

		if( result[j - 1] > max_number )
		{
			for( k = limit - 1; k > 0; k-- )
			{
				if( result[k] >= max_number)
				{	
					result[k] = 1;
					result[k-1]++;
				}
			}
			for( k = 0; k < limit-1; k++ )
			{
				for( l = limit - 1; l > 0; l-- )
				{
					while( result[l] <= result[l-1] && result[l] < max_number)
					{
											printf("dsadasjdk");
						if(result[l] < max_number)
						{
							result[l]++;
						}
					}
				}
			}
		}
	}
	getch();
}