#include<stdio.h>
#include<conio.h>
struct date
{
	int dd,mm,yy;
};

struct student
{
	int rollno;
	char nm[100];
	struct date dob;
};

struct student takeinput()
{
	static int i = 0;
	struct student s;
	
	printf("\n Enter rollno%d: ",i++);
	scanf("%d",&s.rollno);
	printf("\n Enter name%d: ",i++);
	scanf("%s",s.nm);
	printf("\n Enter bithdate(dd mm yyyy)");
	scanf("%d %d %d",&s.dob.dd,&s.dob.mm,&s.dob.yy);
	return s;
}
void main()
{
	int nm_val;
	int n =2 ,i;
	struct student s[10];
	printf("\n Enter number of students[MAX 100]");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		s[i]=takeinput();
	}
}