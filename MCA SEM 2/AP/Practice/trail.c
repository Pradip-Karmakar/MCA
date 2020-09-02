#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int no;
	struct node *next;
};


void menu(struct node *, struct node *);
struct node * inputdata(struct node *, struct node *);
void display( struct node *);

void main()
{
	struct node *start = NULL,*list;
	menu(list,start);
}

void menu(struct node *list, struct node *start)
{
	int ch;
	printf("\n Select any option Given Below. \n 1) Insert Data \n 2) Display Data \n 3) Exit !  \n");
	scanf("%d",&ch);

	if(ch > 0 && ch < 4)
	{
		switch(ch)
		{
			case (1): 
				start = inputdata(list,start);
				menu(list,start);
			case (2): 
				display(start);
				menu(list,start);
			default : 
				exit(0);
		}
	}
	else
	{
		printf("\n Invalid Selection.");
		menu(list,start);
	}
}

struct node * inputdata(struct node *list, struct node *start)
{
	struct node *temp;
	int n;

	printf("\n Enter a Number : ");
	scanf("%d",&n);

	temp = start;
	list = (struct node *)malloc(sizeof(struct node));

	if(temp == NULL)
	{
		start = list;
		temp = start;
	}
	else
	{

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

	}

	temp->next = list;
	list->no = n;
	list->next = NULL;
	return start;
}

void display( struct node *start)
{
	int count = 0;
	struct node *temp;

	temp = start;

	if(temp == NULL)
	{
		printf("\n Link List is Empty !");
	}
	else
	{
		while(temp != NULL)
		{
			temp =temp->next;
			count++;
		}

		printf("\n No of Count : %d",count);
	}
}



