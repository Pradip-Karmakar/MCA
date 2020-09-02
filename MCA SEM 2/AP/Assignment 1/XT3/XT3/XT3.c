#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int dd,mm,yy;
}date;

typedef struct {
	int acc_no;
	float old_balance,new_balance,last_payment;
	char name[15];
	char status[10];
	date dateofpay;
}customer;

customer getData();
void setPrint(customer[],int); 
void menudriven(customer[],int);
void main()
{
	customer c[50];
	int i,total_cust;
	printf("Enter Total Number of Customer : ");
	scanf("%d",&total_cust);
	for( i = 0; i < total_cust; i++ )
	{
		c[i] = getData();
	}

	setPrint(c,total_cust);
	menudriven(c,total_cust);
}

customer getData()
{
	customer s;
	printf("\n\nEnter Account Number : ");
	scanf("%d",&s.acc_no);
	printf("\n\nEnter The Customer's Name : ");
	scanf("%s",s.name);
	printf("\n\nEnter The Old Balance : ");
	scanf("%f",&s.old_balance);
	printf("\n\nEnter The Last Payment : ");
	scanf("%f",&s.last_payment);
	s.new_balance = s.old_balance - s.last_payment;
	if(s.new_balance > 0)
	{
		strcpy(s.status,"Pending");
	}
	else{
		strcpy(s.status,"Clear");
	}
	printf("\n\nEnter The Date of Last Payment [dd mm yy] : ");
	scanf("%d %d %d",&s.dateofpay.dd,&s.dateofpay.mm,&s.dateofpay.yy);
	printf("_________________________________________________________");
	return s;
}

void setPrint(customer s[],int tc)
{
	int i;
	printf("\n\tList Of Customers\n_________________________________________________________");
	for( i = 0; i < tc; i++ )
	{
		printf("\n\n\tCustomer Id = %d \n\tCustomer Name = %s\n\tOld Balance = %.2f\n\tLast Payment = %.2f\n\tLast Payment Date = %d/%d/%d\n\tNew Balance = %.2f\n\n___________________________________________________________________",s[i].acc_no,s[i].name,s[i].old_balance,s[i].last_payment,s[i].dateofpay.dd,s[i].dateofpay.mm,s[i].dateofpay.yy,s[i].new_balance);
	}
}

void menudriven(customer s[],int tc)
{
	int i,j,option,check;
	char name[15];
	printf("\n\nPress 1 To Display All Customer Details. \n\nPress 2 To Display Specific Customer By Name. \n\nPress 3 To Display Status of Customers. \n\nPress 4 To Display Current Balance of Customers. \n\nPress 5 To Exit Program.\n\n");\
	scanf("%d",&option);
	if(option == 1)
	{
		setPrint(s,tc);
		menudriven(s,tc);
	}
	else if(option == 2)
	{
		printf("Enter Customer Name : ");
		scanf("%s",name);
		for( i = 0; i < tc; i++ )
		{
			check = strcmp(s[i].name,name);
			if( check == 0 )
			{
				printf("\n\n\tCustomer Id = %d \n\tCustomer Name = %s\n\tOld Balance = %.2f\n\tLast Payment = %.2f\n\tLast Payment Date = %d/%d/%d\n\tNew Balance = %.2f \n\tStatus = %s \n\n___________________________________________________________________",s[i].acc_no,s[i].name,s[i].old_balance,s[i].last_payment,s[i].dateofpay.dd,s[i].dateofpay.mm,s[i].dateofpay.yy,s[i].new_balance,s[i].status);
			}
		}
		menudriven(s,tc);
	}
	else if(option == 3)
	{
		for( i = 0; i < tc; i++ )
		{
			printf("\nCustomer Name = %s\n Status = %s\n_________________________________________________________",s[i].name,s[i].status);
		}
		menudriven(s,tc);
	}
	else if(option == 4)
	{
		for( i = 0; i < tc; i++ )
		{
			printf("\nCustomer Name = %s\n Current Balance = %.2f\n_________________________________________________________",s[i].name,s[i].new_balance);
		}
		menudriven(s,tc);
	}
	else if(option == 5)
	{
		exit(0);	
	}
	else
	{
		printf("Please Select Proper Options");
		menudriven(s,tc);
	}
	printf("\nCustomer Does Not Exists.\n");
	menudriven(s,tc);
}