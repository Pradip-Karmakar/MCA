#include <iostream>
using namespace std;
class Stack
{
    class Item
    {
        public:
        int data;
        Item *nextItem;

        Item(int value)
        {
            data = value;
            nextItem = NULL;
        }

        ~Item()
        {
            if (nextItem)
            delete nextItem;
        }
    };
    Item *top;
    short numberOfItems, size;
    public:
        Stack(int size)
        {
            if (size < 1)
                size = 5;
            this->size = size;
            numberOfItems = 0;
            top = NULL;
        }
        
        bool isFull()
        {
            return (numberOfItems >= size);
        }

        bool isEmpty()
        {
            return !top;
        }
 
        void push(int value)
        {
            if (isFull())
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            Item *item = new Item(value);
            item->nextItem = top;
            top = item;
            numberOfItems++;
        }

        int pop()
        {
            if (isEmpty())
            {
                cout << "Stack is empty!" << endl;
                return NULL;
            }
            Item *itemToBeDeleted = top;
            top = itemToBeDeleted->nextItem;
            itemToBeDeleted->nextItem = NULL;
            int deletedData = itemToBeDeleted->data;
            numberOfItems--;
            delete itemToBeDeleted;
            return deletedData;
        }
        void display()
        {
            if (isEmpty())
                cout << "Stack is empty!" << endl;
            else
            {
                cout << "TOP -> ";
                Item *item = top;
                while (item)
                {
                    cout << "-> " << item->data << endl;
                    item = item->nextItem;
                }
            }
        }

        ~Stack()
        {
            if (top)
                delete top;
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
    Stack stack1(size);
    short option;
    int item;

    do
    {
        cout << "\n-> 1. Push\n-> 2. Pop\n-> 3. Display\n-> 0. Exit\n-> ";
        cin >> option;
        switch (option)
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
            case 0:
            break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while (option);
}