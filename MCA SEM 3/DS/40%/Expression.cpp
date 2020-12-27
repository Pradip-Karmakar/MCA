#include<iostream>
#include<cstring>
using namespace std;

class Stack {
    class Value {
        public:
        string data;
        Value *Next;

        Value(char n) {
            data = n;
            Next = NULL;
        }
    };

    Value *top;
    int size, count;
    public:

    Stack(int size)
    {
        if (size < 1)
            size = 5;
        this->size = size;
        count = 0;
        top = NULL;
    }

    bool isFull(){
        return (count >= size);
    }

    bool isEmpty(){
        return !top;
    }

    void push(char n){
        if(isFull()){
            cout << "Overflowed" << endl;
            return;
        }
        Value *val = new Value(n);
        val->Next = top;
        top = val;
        count++;
    }

    void edit(char n){
        if(isEmpty()) {
            cout << "UnderFlowed" << endl;
        }
        top->Next->data += n;
        string poped = pop();
        top->data += poped;
    }

    string pop() {
        string lastdelete = top->data;
        top = top->Next;
        count--;
        return lastdelete;
    }

    void display() {
        if(isEmpty()) 
            cout << "Empty" << endl;
        else 
            cout << top->data << endl;
    }

    bool isOperator(char c) 
    { 
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true; 
        
        return false; 
    } 
};

int main(){
    char Post_Expresion[] = "abc/+de*-";
    int i = 0,length = strlen(Post_Expresion);
    Stack s(length);
    while(Post_Expresion[i] != '\0') {
        if(s.isOperator(Post_Expresion[i])){
            s.edit(Post_Expresion[i]);
        }
        else {
            s.push(Post_Expresion[i]);
        }
        i++;
    }

    s.display();
    return 0;
}