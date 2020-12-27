#include<iostream>
using namespace std;

class Sorting{

    public:

    int list[10], i;

    void getData() {
        i = 0;
        while(i < 10){
            cout << "Enter The " << i << " index element : ";
            cin >> list[i];
            i++;
        }
    }

    void print() {
        i = 0;
        while(i < 10){
            cout << "The Element At index" << i << " : " << list[i] << endl;
            i++;
        }
    }

    void bubblesort() {
         for(i = 0; i < 10 - 1; i++) {
             for(int j = 0; j < 10 - i - 1; j++) {
                 if(list[j] > list[j+1]) {
                     list[j] += list[j+1];
                     list[j+1] = list[j] - list[j+1];
                     list[j] -= list[j+1]; 
                 }
             }
         }
         print();
    }

    void selectionsort() {
        int lowest_index;
         for(i = 0; i < 10 - 1; i++) {
            lowest_index = i;
            for(int j = i + 1; j < 10; j++) {
                if(list[j] < list[lowest_index]) {
                    lowest_index = j; 
                }
            }
            list[i] += list[lowest_index];
            list[lowest_index] = list[i] - list[lowest_index];
            list[i] -= list[lowest_index];
         }
         print();
    }

    void insertionsort() {
        int found_low;
         for(i = 1; i < 10 - 1; i++) {
             if( list[i-1] > list[i] ){
                 int j = i - 1;
                 found_low = list[i];
                 while(j >= 0 && list[j] > list[i]){
                     list[j + 1] = list[j];
                     j--;
                 }
                 list[j + 1] = found_low;
             }
         }
         print();
    }
};


int main(){
    Sorting s;
    s.getData();
    int choice = 0;
    while(1){
        cout << "1. Perform Bubble Sort." << endl << "2. Perform Selection Sort." << endl << "3. Perform Insertion Sort." << endl << "4. Re-insert Data into Array."<< endl << "5. Exit." << endl;
        cin >> choice;
        switch(choice){
            case 1:
                s.bubblesort();
                break;
            case 2:
                s.selectionsort();
                break;
            case 3:
                s.insertionsort();
                break;
            case 4: 
                s.getData();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
    } 
}