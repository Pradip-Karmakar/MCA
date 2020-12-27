#include<iostream>
using namespace std;

class Binary{
    public:
    int arr[10];
     int i = 0;

    Binary(){
        getData();
    }

    void getData(){
        i = 0;
        cout << "Enter Values In array : ";
        while(i != 10){
            cin >> arr[i];
            i++;
        }
    }

    int getNumber(){
        int n;
        cout << "Enter Values You want to Search : ";
        cin >> n;
        return n; 
    }

    int binarySearch(int n) {
        i = 0;
        int j = 9;
        while(j >= i){
            int k = (i+j)/2;
            if(arr[k] < n){
                i = k + 1;
            }
            else if (arr[k] > n) {
                j = k - 1;  
            }
            else{
                return k;
            }
        }
        return -1;
    }
};

int main(){
    Binary l;
    char ch;
    while(1){
               
        int search = l.getNumber();
        int result = l.binarySearch(search);
        if(result < 0) cout << "Value Not Present in Array List." << endl;
        else cout << "Search Value Located At " << result << " index of the array" << endl;
        cout << "Press /'c/' for continue search (Any other character than /'c/' will exit the Program) : ";
        cin >> ch;
        if(ch != 'c')
            exit(0);
    }
}