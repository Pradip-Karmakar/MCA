#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int i, j, k, add_number, mul_number, limit, first[20], add[20], mul[20];
	printf("Enter The Addition Number : ");
	scanf("%d",&add_number);
	printf("Enter The Multiplication Number : ");
	scanf("%d",&mul_number);
	printf("Enter The Limit of Permutation : ");
	scanf("%d",&limit);

	for( i = 0; i < limit; i++ ){
		first[i] = 1;
	}
	for( j = 0; j < pow(100,limit); j++ ){
		for( i = 0; i < limit; i++ ){
			add[i] = first[i];
			mul[i] = first[i];
		}
		if(add && mul)
		{
			for(i = 0; i < limit; i++ )
			{
				printf("%d ",add[i]);
			}
			
		}
		first[i-1] +=1;
		for( k = limit-1; k > 0 ; k--){
			if(first[k] > max_number){
				first[k] = 1;
				first[k-1] += 1;
			}
		}
	printf("\n");
	}
	getch();
}