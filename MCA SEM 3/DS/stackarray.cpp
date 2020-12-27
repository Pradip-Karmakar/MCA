#include <iostream>
using namespace std;
template <typename T>

class Stack
{
    T *data;
    short top, size;
    
    public:
        Stack(int size)
        {
            if (size < 1)
                size = 5;
                this->size = size;
                top = -1;
                data = new T[this->size];
        }

        bool isFull()
        {
            return (top > size - 1);
        }

        bool isEmpty()
        {
            return (top < 0);
        }

        void push(T item)
        {
            if (isFull())
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            data[++top] = item;
        }

        T pop()
        {
            if (isEmpty())
            {
                cout << "Stack is empty!" << endl;
                return NULL;
            }
            return data[top--];
        }

        void display()
        {
            if (isEmpty())
                cout << "Stack is empty!" << endl;
            else
            {
                cout << "TOP -> " << endl;
                for (int i = top; i >= 0; i--)
                cout << "-> " << data[i] << endl;
            }
        }

        ~Stack()
        {
            if (data)
            delete data;
        }
};
void menu();
int main()
{
 menu();
 return 0;
}
void menu()
{
    short size;
    cout << "Enter the size of stack: ";
    cin >> size;
    Stack<int> stack1(size);
    short check;
    int item;
    do
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n-> ";
        cin >> check;
        switch (check)
        {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                stack1.push(item);
            break;
            case 2:
                item = stack1.pop();
                if (item)
                cout << "Deleted Item: " << item << endl;
            break;
            case 3:
                stack1.display();
            break;
            case 4:
            break;
            default:
                cout << "Select Proper Selection." << endl;
        }
    } while (check);
}
