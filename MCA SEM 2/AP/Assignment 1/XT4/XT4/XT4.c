#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int stock;
	char author[15],title[15],publisher[15];
	float price;
}books;

books getData();

void menudriven(books[],int);

void main()
{
	books b[50];
	int i,total_books;
	printf("Enter Total Number of Books : ");
	scanf("%d",&total_books);
	for( i = 0; i < total_books; i++ )
	{
		b[i] = getData();
	}

	menudriven(b,total_books);
}

books getData()
{
	books b;
	printf("\nEnter Book's Author Name : ");
	scanf("%s",b.author);
	printf("\nEnter Book's Title : ");
	scanf("%s",b.title);
	printf("\nEnter Book's Publisher Name : ");
	scanf("%s",b.publisher);
	printf("\nEnter Book Price : ");
	scanf("%f",&b.price);
	printf("\nEnter Book Stock : ");
	scanf("%d",&b.stock);
	printf("______________________________________________");
	return b;
}

void menudriven(books b[],int tb)
{
	int i,j,option,check1,check2,copies;
	char auth[15],title[15];
	float amt;
	printf("\n\n\tPress 1 For Book Availbility \n\n\tPress 2 For Exit\n");
	scanf("%d",&option);
	if(option == 1)
	{
		printf("\nEnter Book Title : ");
		scanf("%s",title);
		printf("\nEnter Author Name : ");
		scanf("%s",auth);
		for( i = 0; i < tb; i++ )
		{
			check1 = strcmp(b[i].title,title);
			check2 = strcmp(b[i].author,auth);
			if(check1 == 0 && check2 == 0)
			{
				printf("\nEnter Number of Copies You Want : ");
				scanf("%d",&copies);
				if(b[i].stock >= copies)
				{
					amt = b[i].price * copies;
					printf("Total Payable Amount For %d Copies Will Be : Rs %.2f",copies,amt);
					menudriven(b,tb);
				}
				else
				{
					printf("Only %d Copies Are Available",b[i].stock);
					menudriven(b,tb);
				}
			}
		}
		printf("Book Not Found");
		menudriven(b,tb);
	}
	else if(option == 2)
	{
		exit(0);
	}
	else
	{
		printf("Please Select Proper Options");
		menudriven(b,tb);
	}
}