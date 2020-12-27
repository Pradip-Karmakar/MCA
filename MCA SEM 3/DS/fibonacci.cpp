#include <iostream>
using namespace std;


int fibonacci(int num) 
{
   if((num==1)||(num==0)) 
   {
      return(num);
   }
   else 
   {
      return(fibonacci(num-1)+fibonacci(num-2));
   }
}
int main() 
{
   int limit, i = 0;
   cout << "Enter the limit for Fibonacci : ";
   cin >> limit;
   cout << "\nFibonnaci Series : ";
   while( i < limit ) {
      cout << " " << fibonacci(i);
      i++;
   }
   return 0;
}