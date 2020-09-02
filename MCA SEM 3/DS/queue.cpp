#include <iostream>
using namespace std;

int queue[10], n = 10, front = -1, rear = -1;


// inserting data into queue
void Inserting_queue_element() {
   int data;
   if (rear == n - 1)
   {
       cout << "Queue is Full" << endl;
   }
   else {
       // if front is -1 then it must be empty so assigning 0 for inserting at first position.
        if (front == -1)
        {
            front = 0;
        }

        cout << "Enter the element for queue : " << endl;
        cin >> data;
        rear++;
        queue[rear] = data;
   }
}


// deleting data from queue 
void Deleting_queue_element() {
    if (front == - 1 ) {
        cout << "Queue is Empty" << endl;
        return ;
    } 
    else{
        cout << "Element " << queue[front] << " is deleted from queue." << endl;
        queue[front] = 0; // no need for assigning 0, its for my understanding & treasing.
        front++;
   }
}


// display all element from the queue
void Display_queue_element() {
    // if front is -1 then it must be empty
    if (front == - 1)
    {
        cout << "Queue is Empty" << endl;
    }
    else{
        cout << "Queue elements are follows " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << endl;
        }
    }
}

// main function
int main() {
   int ch;
   do {
        cout << " 1 :- Insert element into the queue" << endl;
        cout << " 2 :- Delete element from the queue" << endl;
        cout << " 3 :- Display all the elements from the queue" << endl;
        cout << " 4 :- Exit" << endl;
        cout << "Enter your Option : " << endl;
        cin >> ch;
        switch (ch) {
            case 1: 
                Inserting_queue_element();  
            break;
            case 2: 
                Deleting_queue_element();
            break;
            case 3: 
                Display_queue_element();
            break;
            default: cout << "Please Select Proper Option." << endl; // comment for invalid input
        }
    } while(ch!=4); // if found 4 exit otherwise continue
    return 0;
}