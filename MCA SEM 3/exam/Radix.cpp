#include <iostream>
#include<math.h>
using namespace std;

void updateSort(int after[][10],int unsort[], int limit) {
    int unsortindex = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(after[i][j] > 0){
                unsort[unsortindex] = after[i][j];
                unsortindex++;
            }
        }
    }
}

void Digit(int after[][10], int unsort[], int limit,int max) {
    for(int k = 10;k <= pow(10,max-1); k*10 ) {
        for(int i = 0;i < limit; i++) {
            int digit = unsort[i]/(10);
            while(digit > 10){
                digit/=10;
            }
            after[digit][i] = unsort[i];
        }
        updateSort(after,unsort,limit);   
    }
}

int getMaxdigit(int unsort[],int limit) {
    int max = 0;
    for(int i = 0; i < limit; i++){
        if(unsort[i] > max){
            max = unsort[i];
        }
    }
    int count = 0;
    while(max > 0) {
        max/=10;
        count++;
    }
    return count;
}

void print(int aftersorting[][10]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(aftersorting[i][j] != 0)
                cout << aftersorting[i][j] << " ";
        }
        cout << "-------\n";
    }
}

void radixSort(int unsort[],int limit){
    int maxtotalDigit = getMaxdigit(unsort,limit);
    int afterSorting[10][10] = {0};
    Digit(afterSorting,unsort,limit,maxtotalDigit);
    
    cout << "Output : " << endl;
    print(afterSorting);
}

int main() {
    int unsortedList[20],limit = 0;
    cout << "Enter total number of the data : ";
    cin >> limit;
    for(int i = 0; i < limit; i++) {
        cin >> unsortedList[i];
    }
    
    radixSort(unsortedList, limit);
    return 0;
}

