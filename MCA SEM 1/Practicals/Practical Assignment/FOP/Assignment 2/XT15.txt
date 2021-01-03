#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int i, j, k, max_number, limit, power, store[20];
	printf("Enter The Maximum Number : ");
	scanf("%d",&max_number);
	printf("Enter The Limit of Permutation : ");
	scanf("%d",&limit);
	for( i = 0; i < limit; i++ ){
		store[i] = 1;
	}
	power = pow(max_number,limit);
	for( j = 0; j < power; j++ ){
		for( i = 0; i < limit; i++ ){
			printf("%d ",store[i]);
		}
		store[i-1]++;
		if(store[limit-1] > max_number){
			for( k = limit-1; k > 0; k--){
				if(store[k] > max_number){
					store[k] = 1;
					store[k-1]++;
				}
			}
		}
	printf("\n");
	}
	getch();
}