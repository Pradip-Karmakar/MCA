#include <iostream>
using namespace std;

// Get User Input
int input()
{
    int n;
    cout << "Enter The Number";
    cin >> n;
    return n; 
}


// factorial function return all the factorial value until the limit
int factorial(int n)
{
   if (n < 2)
   {
       return 1;
   }
   else
   {
       return n*factorial(n-1);
   }
}


int main() {
   int n = input();
   cout << "Factorial of " << n << " is " << factorial(n);
   return 0;
}