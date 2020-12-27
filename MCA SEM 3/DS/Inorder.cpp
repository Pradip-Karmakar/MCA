#include<iostream>
using namespace std;

struct Tree {
    struct Tree *left;
    int data;
    struct Tree *right;
};

class Stack { 

    int top;
    struct Prev {
        struct Tree *node;
        struct Prev *next;
    };

    public:
    struct Prev *stack,*head = NULL,*temp_Prev = NULL;

    Stack()
    { 
        top = -1; 
    }

    void push(struct Tree *temp){
        stack = (struct Prev *)malloc(sizeof(struct Prev));
        ++top;
        stack->node = temp;
        stack->next = head;
        head = stack;
    }

    struct Tree * pop(){
        if(top == -1){
            cout << "Stack Overflowed" << endl;
            return;
        }
        else{
            top--;
            temp_Prev = head;
            head = head->next;
            return temp_Prev->node;
        }
    }

    bool isEmpty(){
        if(top == -1)
                return false;
        else
                return true;
    }
    
};

void InorderTraversal(struct Tree);

int main()
{
    struct Tree *node, *head;
    InorderTraversal(head);
    return 0;
}

void InorderTraversal(struct Tree *head){
    Stack s;
    struct Tree *temp;
    temp = head;
    while(temp != NULL || s.isEmpty()) {
        if(temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        else {
            temp = s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

