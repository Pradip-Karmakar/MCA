#include<iostream>
using namespace std;
class hello
{
    int a;
    public:
    int print(int b,int c)
    {
        cout << b << endl;
        cout << c << endl;
        a = b + c;
        return a;
    }
};

int main() 
{
    char a[10];
    int get,b,c;
    hello h;
    cout << "Enter Your Name : ";
    cin >> a;
    cout << a << endl;
    cin >> b;
    cin >> c;
    get = h.print(b,c);
    cout << get;
    return 0;
}