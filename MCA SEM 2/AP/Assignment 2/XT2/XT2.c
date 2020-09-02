#include<stdio.h>
#include<conio.h>

void getnumbers(int *,int);
void findmaxmin(int *, int, int *, int *);
int getlimit();

void main()
{
    int numbers[20],limit,*ptr,*max,*min;
    ptr = numbers;
    limit = getlimit();
    getnumbers(ptr,limit);
    findmaxmin(ptr,limit,max,min);
}

void getnumbers(int *p,int limit)
{
    int i = 0;
    while( i < limit )
    {
        printf("Fill Number %d : ",i+1);
        scanf("%d",p);
        p++;
        ++i;
    } 
}

int getlimit()
{
    int l;
    printf("Enter Total Numbers You Want : ");
    scanf("%d",&l);
    return l;
}

void findmaxmin(int *p, int limit, int *max, int *min)
{
    int i;
    max = p;
    min = p;
    for( i = 0; i < limit; i++ )
    {
        if( *p > *max )
        {
            max = p;
        }
        else if( *p < *min )
        {
            min = p;
        }
        p++;
    }
    printf("\nMaximum Number : %d at Address %p\n",*max,max);
    printf("\nMinimum Number : %d at Address %p\n",*min,min);
}