#include<stdio.h>
#include<conio.h>
#include<string.h>
void convert(char a[20],int,int);
void main()
{
	char arr[20];
	int base1,base2;
	printf("Enter the base : ");
	scanf("%d",&base1);
	printf("Enter the input : ");
	scanf("%s",arr);
	printf("Enter the base to convert : ");
	scanf("%d",&base2);
	convert(arr,base1,base2);
	getch();
}
void convert(char a[20], int b1, int b2)
{
	int i, r, n = 0, b = 1, count = 0, result;
	for(i=strlen(a)-1;i>=0;i--)
	{
		if(a[i] >= 'A' && a[i] <= 'Z')
		{
			result = a[i]-'0'-7;
		}
		else
		{
			result = a[i]-'0';
		}
		n = result*b+n;
		b *=b1;
	}

	while(n != 0)
	{
		r = n%b2;
		result='0'+r;
		if(result > '9')
		{
			result +=7;
		}
		a[count]=result;
		count++;
		n=n/b2;
	}
	for(i = count-1; i >= 0; i--)
	{
		printf("%c",a[i]);
	}

}
