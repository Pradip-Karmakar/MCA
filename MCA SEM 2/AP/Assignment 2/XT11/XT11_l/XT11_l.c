#include<stdio.h>
#include<conio.h>
#include<string.h>

int getlist();
void getdata(char[][15],int);
void sort(char[][15],int);
void printdata(char[][15],int);

void main()
{
	char string[10][15],list;

	list = getlist();
	getdata(string,list);
	sort(string,list);
	printdata(string,list);
	getch();
}

int getlist()
{
	int x;
	printf("Enter The List Strings Count : ");
	scanf("%d",&x);
	return x;
}

void getdata(char s[][15],int list)
{
	int i, j;
	char (*ptr)[15];
	ptr = s;
	for( i = 0; i < list; i++)
	{
		scanf("%s",*ptr);
		ptr++;
	}
}

void sort(char s[][15],int list)
{
	int i, j,check = 0;
	char (*ptr)[15],temp[15];
	ptr = s;
	for( i = 0; i < list - 1; i++ )
	{
		for( j = 0; j < list - i - 1; j++ )
		{
			check = strcmp(*(ptr + j), *(ptr + j + 1));
			if(check > 0)
			{
				strcpy(temp,*(ptr + j));
				strcpy(*(ptr + j),*(ptr + j + 1));
				strcpy(*(ptr + j + 1),temp);
			}
		}
	}
}

void printdata(char s[][15],int list)
{
	int i, j;
	char (*ptr)[15];
	ptr = s;
	printf("\n\n______________________After Sorting____________________\n");
	for(i = 0; i < list; i++)
	{
		printf("%s\n",*ptr);
		ptr++;
	}
}