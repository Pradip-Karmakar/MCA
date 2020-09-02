#include<stdio.h>
#include<conio.h>
struct date{
	int dd,mm,yy;
};
struct student{
	int r;
	char name;
	float marks[3];
	struct date dob;
};
void getdata(struct student);
void getprint(struct student);
struct date getdate();
void main()
{
	struct date today;
	struct student s[5];
	getdata(s);
	today = getdate();
	getprint(s);
}
void getdata(struct student s)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("\nEnter The Roll_No & Name for Student %d: ",i+1);
		scanf("%d %s",&s[i].r,s[i].name);
		for(j=0;j<3;j++)
		{
			printf("\nEnter Marks Of Subject %d : ",j+1);
			scanf("%f",&s[i].marks[j]);
		}
		printf("Enter The Date of Birth : ")
		scanf("%d %d %d",&s[i].dob.dd,&s[i].dob.mm,&s[i].dob.yy);
	}	
}

struct date getdate()
{
	struct date d;
	printf("Enter Todays Date : ");
	scanf("%d %d %d",&d.dd,&d.mm,&d.yy);
	return d;
}

void getprint(struct student s)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("%d\t%s\t",s[i].r,s[i].name);
		for(j=0;j<3;j++)
		{
			printf("%f\t",s[i].marks[j]);
		}
		printf("%d-%d-%d\t",s[i].dob.dd,s[i].dob.mm,s[i].dob.yy);
	}
}