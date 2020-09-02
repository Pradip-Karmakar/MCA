#include<stdio.h>
#include<conio.h>

int getcolrow(int);
void getdata(int[][50],int,int);
void multiply(int[][50],int[][50],int[][50],int,int);
void printdata(int[][50],int,int);


void main()
{
	int i, j, mat1[50][50], mat2[50][50], rest[50][50];
	i = getcolrow(1);
	j = getcolrow(2);
	getdata(mat1,i,j);
	getdata(mat2,i,j);
	multiply(mat1,mat2,rest,i,j);
	printdata(rest,i,j);
	getch();
}

int getcolrow(int x)
{
	int *p;
	p = &x;
	if( *p == 1 )
	{
		printf("Enter The Rows : ");
	}
	else
	{
		printf("Enter The Columns : ");
	}
	scanf("%d",p);
	return *p;
}

void getdata(int matrix[][50],int r,int c)
{
	int i,j,(*ptr)[50];
	ptr = matrix;
	for( i = 0; i < r; i++ )
	{
		for( j = 0; j < c; j++ ) 
		{
			printf("\nEnter The (%d,%d) of matrix : ",i,j);
			scanf("%d",(*(ptr + i) + j));
		}
	}
}

void multiply(int mat1[][50], int mat2[][50], int rest[][50], int r, int c)
{
	int i , j, k, temp=0,(*ptr)[50],(*ptr2)[50],(*ptr3)[50];
	ptr = mat1;
	ptr2 = mat2;
	ptr3 = rest;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				temp += (*(*(ptr + i) + k)) * (*(*(ptr2 + k) + j));
			}
			*(*(ptr3 + i) + j) = temp;
			temp=0;
		}
		printf("\n");
	}
}

void printdata(int rest[][50],int r, int c)
{
	int i,j,(*ptr3)[50];
	ptr3 = rest;
	for( i = 0; i < r; i++ )
	{
		for( j = 0; j < c; j++)
		{
			printf("%3d",*(*(ptr3 + i) + j));
		}
		printf("\n");
	}
}