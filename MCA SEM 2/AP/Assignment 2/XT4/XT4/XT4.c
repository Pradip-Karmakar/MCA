
#include<stdio.h>
#include<conio.h>

int getrow();
int getcol();
void getdata(int[][50],int,int);
void transpose(int[][50],int[][50],int,int);
void printdata(int[][50],int,int);

void main()
{
	int matrix[50][50],temp[50][50],i,j;
	i = getrow();
	j = getcol();
	getdata(matrix,i,j);
	transpose(matrix,temp,i,j);
	printdata(temp,i,j);
	getch();
}

int getrow()
{
	int n;
	printf("Enter The Number Rows : ");
	scanf("%d",&n);
	return n;
}

int getcol()
{
	int n;
	printf("Enter The Number Columns : ");
	scanf("%d",&n);
	return n;
}

void getdata(int matrix[][50],int r, int c)
{
	int i,j,(*ptr)[50];
	ptr = matrix;
	 for( i = 0; i < r; i++ )
	 {
		for( j = 0; j < c; j++ )
		{
			printf("Enter The Value for Matrix[%d][%d] : ",i,j);
			scanf("%d",(*(ptr + i)+ j));
		}
	 }
}

void printdata(int temp[][50],int r, int c)
{
	int i,j,(*ptr)[50];
	ptr = temp;
	 for( i = 0; i < c; i++ )
	 {
		for( j = 0; j < r; j++ )
		{
			printf("%3d",i,j,*(*(ptr + i) + j));
		}
		printf("\n");
	 }
}

void transpose(int matrix[][50], int temp[][50],int r, int c)
{
	int i,j,(*ptr)[50], (*ptr2)[50];
	ptr = matrix;
	ptr2 = temp;
	for( i = 0; i < r; i++ )
	{
		for( j = 0; j < c; j++ )
		{
			*(*(ptr2 + j) + i) = *(*(ptr + i) + j);
		}
	}
}