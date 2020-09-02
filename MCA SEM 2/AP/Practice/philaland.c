#include<stdio.h>
#include<conio.h>

/* function declaration */
int get_test_case();
void get_max_price( int, int[] );
void get_combination( int, int[] );
void find_output(int);
int getn( int[] );
void printoutput( int[], int, int );

/* main function */
void main()
{
	int T,N[100];
  	T = get_test_case();
    get_max_price(T,N);
    get_combination(T,N);
    getch();
}

/* Test Case Input function */
int get_test_case()
{
    int t;
    printf("\nEnter Number Of Test Cases You Want : ");
    scanf("%d",&t);
    if( t > 0 && t < 100 )
    {
        return t;
    }
    else{
        printf("\nInput Criteria for Test Cases between 1 to 100.\n");
        get_test_case(t);
    }
}

/* Maximum Price Input function */
void get_max_price(int t, int n[])
{
    int i;
    for( i = 0; i < t; i++ )
    {
        printf("\nEnter The Maximum price of item in Island (Test case %d) (Input Criteria : 1-5000)  : ", i+1);
        scanf("%d",&n[i]);
        if( n[i] < 1 || n[i] > 5000 )
        {
            printf("\nInput Criteria for Maximum price between 1 to 5000.\n");
            --i;
        }
    }
}

/* Test Case loop function */
void get_combination( int t, int n[] )
{
    int i = 0, count = getn(n);
    for( i = 0; i < count; i++ )
    {
       find_output(n[i]);
    }
}

/* Finding combination for single test case function */
void find_output(int n)
{
    int cfact = 0, answer[20] = {0}, j = 0;
    float nfact = n;
        for( j = 0; nfact > 1 ; j++ )
        {
            nfact /= 2;
            cfact = nfact;
            if( nfact > cfact && cfact != 0 )
            {
                nfact += 0.5;
            }
            answer[j] = nfact;
        }
        printoutput(answer,j,n);
}

/* Count Array Elements function */
int getn( int n[] )
{
    int c = 0;
    while(n[c] != '\0' && n[c] != 0)
    {
        c++;
    }
    return c;
}

/* Print Output function */
void printoutput( int ans[], int j, int max_price )
{
    int count = getn(ans),i;
    printf("\nCombination for %d : ",max_price);
    for( i = count-1; i >= 0; i-- )
    {
        printf(" %d ",ans[i]);
    }
    printf("\nMinimum Coins to be Used = %d\n",j);
}
