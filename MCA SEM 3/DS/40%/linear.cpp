#include<iostream>
using namespace std;

class Linear{
    public:
    int arr[10];
    int i = 0;

    Linear(){
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

    int linearsearch(int n) {
        i = 0;
        while(i != 10){
            if(arr[i] == n) {
                return i;
            }
        i++;
        }
        return -1;
    }
};

int main(){
    Linear l;
    char ch;
    while(1){
        int search = l.getNumber();
        int result = l.linearsearch(search);
        cout << result << endl;
        if(result < 0) cout << "Value Not Present in Array List." << endl;
        else cout << "Search Value Located At " << result << " index of the array" << endl;
        cout << "Press /'c/' for continue search (Any other character than /'c/' will exit the Program) : ";
        cin >> ch;
        if(ch != 'c')
            exit(0);
    }
    return 0;
}