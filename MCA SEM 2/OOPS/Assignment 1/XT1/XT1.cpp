#include<iostream>
using namespace std;

class statt{
    static int a;
    public:
    statt()
    {
        ++a;
    }
    void print(void)
    {
        cout << "Count : " << a << endl;
    }
};

int statt::a;
int main()
{
    statt s,s1;
    s.print();
    statt s2;
    s.print();
    return 0;
}