#include<stdio.h>
#include<conio.h>
#include<string.h>

int getn()
{
int n;
printf("\n Enter How many String You want ?" );
scanf("%d",&n);
return n;
}

void getdata(char s[][10], int n)//edited
{
int i;
for(i=0;i<n;i++)
{
printf("\n Enter String %d : ",i+1);
scanf("%s",s[i]);
}
}

void sort(char s[][10], int n)//edited
{
int i,j,count;
char temp[20];

for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)//edited
{
count = strcmp(s[j], s[j+1]);
if(count >0 )//edited
{
strcpy(temp ,s[j]);
strcpy(s[j] , s[j+1]);
strcpy(s[j+1], temp);
}
}
}
}

void display(char s[][10], int n)//edited
{
int i;

for(i=0;i<n;i++)
{
printf("\n %s ",s[i]);
}
}

void main()
{
char s[20][10];
int n;
n = getn();
getdata(s,n);
sort(s,n);
display(s,n);

getch();
}