#include <iostream> 
using namespace std; 

int *multiply(int A[], int B[], int m, int n) 
{ 
   int *prod = new int[m+n-1]; 

   for (int i = 0; i<m+n-1; i++) 
     prod[i] = 0; 
  

   for (int i=0; i<m; i++) 
   { 
     for (int j=0; j<n; j++) 
     {
       prod[i+j] += A[i]*B[j]; 
     }
   } 
   return prod; 
} 
  
void print(int poly[], int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
       cout << poly[i]; 
       if (i != 0) 
       {
          cout << "x^" << i ; 
       }
        
       if (i != n-1) 
       {
          cout << " + "; 
       }
    } 
} 
  
//main function
int main() 
{ 
    int A[] = {10, 20, 30}; 
    int B[] = {40, 30, 20, 10};  
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
  
    cout << "First polynomial is " << endl; 
    print(A, m); 
    cout << endl << "Second polynomial is " << endl; 
    print(B, n); 
  
    int *prod = multiply(A, B, m, n); 
  
    cout << endl << "Product polynomial is " << endl; 
    print(prod, m+n-1); 
  
    return 0; 
} 