#include <iostream>
#include <conio.h>
using namespace std;

class add
{
	int a;
	public:
		void addition(int first,int second)
		{
			a = first + second;
			cout << a;
		}
		int addo(int first,int second)
		{
			a = first + second;
			return a;
		}
};

int main()
{	
	int a,b,rtpro;
	add pro;
	cout << "Enter Your Name : ";
	cin >> a;
	cin >> b;
	pro.addition(a,b);
	rtpro = pro.addo(a,b);
	cout << rtpro;
	getch();
	return 0;
}