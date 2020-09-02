#include<stdio.h>
#include<conio.h>

int getData(int[], int);
int reverseData(int[], int);

void main()
{
    int numbers[20], n, i;
    int *p = numbers;
    printf("Enter Total Number of data You Want : ");
    scanf("%d",&n);
    getData(numbers, n);
    reverseData(numbers, n);
    printf("\n");
}

int getData(int arr[], int n)
{
    int i;
    int *ptr = arr;
    for (i = 0; i < n; ++i) {
        printf("Enter Number %d : ", i + 1);
        scanf("%d",ptr);
        ptr++;
    }
}

int reverseData(int arr[], int n)
{
    int i, *ptr = arr + n - 1;
    printf("\nNumbers in reverse Order \n");
    for (i = 0; i < n; i++) {
        printf("%d ", *ptr);
        ptr--;
    }
}
