#include <stdio.h>
#include <conio.h>

void weeding(int []);
void print(int []);
void main()
{
    int num[10] = {10,20,30,40,50,60,70,80,90,100};
    print(num);
    weeding(num);
    print(num);
    getch();
}

void print(int a[])
{
    int i;
    for( i = 0; i < 10; i++ ) {
        printf(" %d |",a[i]);
    }
}

void weeding(int a[])
{
    int i, j, ind, temp,temp1, temp2;

    printf("Enter The Index (1 - 10) For Switch : ");
    scanf("%d",&ind);

    temp = ind;
    for( i = 9; i >= ind; i-- ) {
        temp1 = a[9];
        for( j = 9; j > 0; j-- ) {
            temp2 = a[j-1];
            a[j] = temp2;
        }   
        a[j] = temp1;
    }

    // for( i = 0; temp < 10 ; i++ ) {
    //     arr[i] = a[temp];
    //     temp++;
    // }

    // temp = ind;
    // for ( j = 0; j < temp; j++ ) {
    //     arr1[j] = a[j];
    // }

    // k = 10 - ind;
    // for( i = 0; i < k; i++ ) {
    //     a[i] = arr[i];
    // }

    // k = 0;
    // for( j = i; j < 10; j++ ){
    //     a[j] = arr1[k];
    //     k++;
    // } 
}