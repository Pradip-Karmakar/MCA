#include <iostream> 
using namespace std; 
  
// max function
int max(int m, int n) 
{  
    return (m > n)? m: n; 
}
 
// addition funtion
int *add(int A[], int B[], int m, int n) 
{ 
   int size = max(m, n); 
   int *sum = new int[size]; 
  
   for (int i = 0; i<m; i++) 
     sum[i] = A[i]; 
  

   for (int i=0; i<n; i++) 
       sum[i] += B[i]; 
  
   return sum; 
} 
  
// print function
void print(int poly[], int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
       cout << poly[i]; 
       if (i != 0) 
        cout << "x^" << i ; 
       if (i != n-1) 
       cout << " + "; 
    } 
} 
  
// main funtion 
int main() 
{ 
    int A[] = {10, 20, 30}; 
    int B[] = {40, 30, 20, 10}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
  
    cout << "First polynomial is \n"; 
    print(A, m); 
    cout << "\nSecond polynomial is \n"; 
    print(B, n); 
  
    int *sum = add(A, B, m, n); 
    int size = max(m, n); 
  
    cout << "\nsum polynomial is \n"; 
    print(sum, size); 
  
    return 0; 
} 