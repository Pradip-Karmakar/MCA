#include<stdio.h>
#include<conio.h>
void breakdown(int number,int a[],int limit)
{
	int i = 0, j, final_ans = 0, quetionant = 0;
	for( j = 0; j < limit; j++ ){
		final_ans += number;
		while(number){
			quetionant  = number%10;
			number = number/10;
			final_ans += quetionant; 
			i++;
		}
		a[j] = final_ans;
		number = final_ans;
		final_ans = 0;
	}
}

void main()
{
	int i, j, start, limit, number, split[100];
	printf("Enter The Starting Number : ");
	scanf("%d",&start);
	printf("Enter The Limit : ");
	scanf("%d",&limit);
	number=start;
	breakdown(number,split,limit);
	for(i = 0; i < limit; i++){
		printf("%d\n",split[i]);
	}

getch();
}
