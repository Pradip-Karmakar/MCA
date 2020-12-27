#include<iostream> 
#include <stack>
using namespace std; 
  

int checkSym(char symbol) 
{ 
    if(symbol == '*' || symbol == '/') 
    return 2; 
    else if(symbol == '+' || symbol == '-') 
    return 1; 
    else
    return -1; 
} 

void infixToPostfix(string s) 
{ 
    std::stack<char> myStack; 
    myStack.push('N'); 
    int l = s.length(); 
    string finalString; 
    for(int i = 0; i < l; i++) 
    { 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
            finalString+=s[i]; 
        else if(s[i] == '(')   
            myStack.push('(');         
        else if(s[i] == ')') 
        { 
            while(myStack.top() != 'N' && myStack.top() != '(') 
            { 
                char c = myStack.top(); 
                myStack.pop(); 
                finalString += c; 
            } 
            if(myStack.top() == '(') 
            { 
                myStack.pop(); 
            } 
        } 
        else
        { 
            while(myStack.top() != 'N' && checkSym(s[i]) <= checkSym(myStack.top())) 
            { 
                char c = myStack.top();
                myStack.pop(); 
                finalString += c; 
            } 
            myStack.push(s[i]); 
        } 
  
    } 
    while(myStack.top() != 'N') 
    { 
        char c = myStack.top(); 
        myStack.pop(); 
        finalString += c; 
    } 
      
    cout <<"Postfix : " << finalString << endl;
} 
  
int main() 
{ 
    string expression = "(a+b+c+d)/(x-y+z*f)"; 
    infixToPostfix(expression); 
    return 0; 
} 