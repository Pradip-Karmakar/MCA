#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int i, j, k, l, Add_number, Mul_number, limit, Combination = 0, Array_Print[20], break_1 = 0, flag = 0, power;
	printf("Enter The Addtion Number : ");
	scanf("%d",&Add_number);
	printf("Enter The Multiplication Number : ");
	scanf("%d",&Mul_number);
	printf("Enter The Combination Limit : ");
	scanf("%d",&limit);

	
	power = pow(Add_number-2,limit);

	for( i = 0; i < limit; i++ )
	{
		Array_Print[i] = 1;
	}

	for( i = 0; i < power; i++ )
	{
		for( j = 0; j < limit; j++ )
		{
			Combination +=  Array_Print[j];
		}

		if( Combination == Add_number )
		{
			Combination = 1;
			for( k = 0; k < limit; k++ )
			{
				Combination *=  Array_Print[k];
			}

			if( Combination == Mul_number )
			{
				flag = 0;
				for( l = 0; l < limit; l++)
				{
					printf("%d ",Array_Print[l]);
				}
			break_1 = 1;
			}
			else
			{
				flag = 1;
			}
			if(break_1 == 1)
			{
				break;
			}
		}
		Combination = 0;
		Array_Print[j-1]++;
		for( k = limit-1; k > 0 ; k--)
		{
			if(Array_Print[k] > Add_number-2)
			{
				Array_Print[k] = 1;
				Array_Print[k-1]++;
			}
		}
	}
	if(flag)
	{
		printf("No Combination Found");
	}
getch();
}