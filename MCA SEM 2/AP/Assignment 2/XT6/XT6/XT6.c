#include<stdio.h>
#include<conio.h>

int getrowcol(int);
void getdata(int[][50],int,int);
void add(int[][50],int[][50],int[][50],int,int);
void printdata(int[][50],int,int);
void main()
{
	int mat1[50][50],mat2[50][50],rest[50][50],row,col;
	row = getrowcol(1);
	col = getrowcol(2);
	printf("\nMatrix 1\n__________\n");
	getdata(mat1,row,col);
	printf("\nMatrix 2\n__________\n");
	getdata(mat2,row,col);
	add(mat1,mat2,rest,row,col);
	printf("\nMatrix 1\n__________\n");
	printdata(mat1,row,col);
	printf("\nMatrix 2\n__________\n");
	printdata(mat2,row,col);
	printf("\nResult\n__________\n");
	printdata(rest,row,col);
	getch();
}

int getrowcol(int x)
{
	int *p;
	p = &x;
	if(*p == 1)
	{
		printf("\nEnter The Rows For Matrix : ");
	}
	else
	{
		printf("\nEnter The Columns For Matrix : ");
	}
	scanf("%d",p);
	return *p;
}

void getdata(int matrix[][50],int r,int c)
{
	int i, j, (*ptr)[50];
	ptr = matrix;
	
	for( i = 0; i < r; i++ )
	{
		for( j = 0; j < c; j++ )
		{
			printf("\nEnter The Value For Matrix[%d][%d] : ",i,j);
			scanf("%d",(*(ptr + i) + j));
		}
	}
	printf("_______________________________________________\n");
}

void add(int matrix1[][50],int matrix2[][50],int resultmatrix[][50],int r, int c)
{
	int i, j,(*ptr)[50],(*ptr2)[50],(*ptr3)[50];
	ptr = matrix1;
	ptr2 = matrix2;
	ptr3 = resultmatrix;
	for( i = 0; i < r; i++ )
	{
		for( j = 0; j < c; j++ )
		{
			*(*(ptr3 + i) + j) = (*(*(ptr + i) + j)) + (*(*(ptr2 + i) + j));
		}
	}
}

void printdata(int matrix[][50],int r, int c)
{
	int i, j, (*ptr)[50];
	ptr = matrix;
	
	for( i = 0; i < r; i++ )
	{
		for( j = 0; j < c; j++ )
		{
			printf("%3d",*(*(ptr + i) + j));
		}
		printf("\n");
	}
}