#include<stdio.h>
struct date{
	int dd,mm,yy;
};
struct student{
	int r;
	char name[15];
	float marks[3];
	struct date dob;
};
void getdata(struct student[]);
void getprint(struct student[]);
struct date getdate();
int getage(struct date, struct student[],int);
void main1()
{
	struct student s[5];
	getdata(s);
	getprint(s);
}
void getdata(struct student s[])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("\nEnter The Roll_No & Name for Student %d: ",i+1);
		scanf("%d %s",&s[i].r, s[i].name);
		for(j=0;j<3;j++)
		{
			printf("\nEnter Marks Of Subject %d : ",j+1);
			scanf("%f",&s[i].marks[j]);
		}
		printf("Enter The Date of Birth : ");
		scanf("%d %d %d",&s[i].dob.dd,&s[i].dob.mm,&s[i].dob.yy);
	}	
}

struct date getdate()
{
	struct date d;
	printf("Enter Todays Date : ");
	scanf("%d %d %d",&d.dd, &d.mm, &d.yy);
	return d;
}

void getprint(struct student s[])
{
	int i,j,showage;
	struct date today = getdate();
	for(i=0;i<5;i++)
	{
		printf("%d\t%s\t",s[i].r,s[i].name);
		for(j=0;j<3;j++)
		{
			printf("%.2f\t",s[i].marks[j]);
		}
		printf("%d-%d-%d\t",s[i].dob.dd, s[i].dob.mm, s[i].dob.yy);
		showage = getage(today,s,i);
		if(showage == 0)
		{
			printf("Underage");
		}
		else
		{
			printf("%d\n",showage);
		}
	}
}

int getage(struct date t,struct student s[],int i)
{
	int year;
	int month;
	int day;
	int age = 20;

	year = t.yy - s[i].dob.yy;
	month = t.mm - s[i].dob.mm;
	day = t.dd - s[i].dob.dd;

	if(year > age)
	{
		if(month >= 0)
		{
			if(day >= 0)
			{
				return year;
			}
		}
		year -= 1;
		return year;
	}
	else if(year == age)
	{
		if(month >= 0)
		{
			if(day >= 0)
			{
				return year;
			}
		}
	}
	return 0;
}
