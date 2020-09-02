#include<stdio.h>
#include<conio.h>

int getlimit(int);
void getdata(int [],int);
int setdata(int [],int,int);
void printdata(int [],int);
void main()
{
    int arr[50],limit,setme;
    limit = getlimit(1);
    getdata(arr,limit);
    setme = getlimit(2);
    limit = setdata(arr,limit,setme);
    printdata(arr,limit);
    getch();
}

int getlimit(int i)
{
    int n;
    if( i == 1 )
    {
        printf("Enter The Total Number You Want in Array : ");
    }
    else
    {
        printf("Enter The Number You Want to set in Array : ");
    }
    
    scanf("%d",&n);
    return n;
}

void getdata(int arr[],int l)
{
    int i,*ptr;
    ptr = arr;
    for( i = 0; i < l; i++,ptr++ )
    {
        scanf("%d",ptr);
    }
}

int setdata(int arr[],int l,int set)
{
    int i,*ptr,temp = 0;
    ptr = arr;

    for(i=0;i<l;i++,ptr++)
    {
        if(set <= *ptr)
        {
            temp = *ptr;
            *ptr = set;
            ++ptr;
            while( *ptr != '\0')
            {
                set = temp;
                temp = *ptr;
                *ptr = set;
                ptr++;
            }
            *ptr = temp;
            l = l+1;
            i = l;
        }
    }
    return l;
}

void printdata(int arr[],int l)
{
    int i, *ptr;
    ptr = arr;
    for ( i = 0; i < l; i++,ptr++)
    {
         printf("%d\n",*ptr);
    }
}