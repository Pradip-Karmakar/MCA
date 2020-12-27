#include<iostream>
using namespace std;

// Structure Declaration
struct node{
    int data;  
    struct node *next;
};

// Functions Declaration
void menu(struct node *,struct node *);
int get_n(char);
struct node * insert_beg(struct node *,struct node *,int);
struct node * insert_end(struct node *,struct node *, int);
struct node * insert_atany(struct node *,struct node *, int);
struct node * delete_data(struct node *,struct node *, int);
void display_link(struct node *);

// Void Main
int main()
{
    struct node *struct_new;
    struct node *head = NULL;
    menu(struct_new,head); // Calling menu funtion
    return 0;
}

// menu function
void menu( struct node *struct_new, struct node *head )
{
    int n,getnum;
    cout << "\n 1 . Add New Data To Linklist From Begining. \n 2 . Add New Data To Linklist From Ending.\n 3 . Add New Data To Linklist At Any Place. \n 4 . Delete a Number From The Link-List. \n 5 . Display LinkList Till Now. \n 6 . Exit. \n";
    cin >> n;
    // Switch case which check the user input and run specified function
    switch(n)
    {
        case(1):
            getnum = get_n('i');
            head = insert_beg(struct_new,head,getnum);   //insertion from begining linklist function call 
            menu(struct_new,head);    //void menu function call
        case(2):
            getnum = get_n('i');
            head = insert_end(struct_new,head,getnum);   //insertion from ending linklist function call 
            menu(struct_new,head);    //void menu function call
        case(3):
            getnum = get_n('i');
            head = insert_atany(struct_new,head,getnum);   //insertion from any point linklist function call 
            menu(struct_new,head);    //void menu function call
        case(4):
            getnum = get_n('d');
            head = delete_data(struct_new,head,getnum);
            menu(struct_new,head);
        case(5):
            display_link(head);     //display linklist function call 
            menu(struct_new,head);     //void menu function call
        case(6):
            exit(0);    //exit function call which terminated the program
        default:
            cout << "\n Please Enter Valid Number.";
            menu(struct_new,head);     //void menu function call
    }
}

// function for taking input from user

int get_n(char a)
{
    int n;
    if( a == 'i' )
    {
        cout << " Enter The Number : ";
    }
    else{
        cout << " Enter The Number to Delete : ";
    }
    scanf("%d",&n);
    return n;
}

//  function insert_beg, use for linklist begining insertion 
struct node * insert_beg( struct node *struct_new, struct node *head,int n )
{
    struct_new = (struct node *)malloc(sizeof(struct node));  
    struct_new->data = n;
    struct_new->next = head;
    head = struct_new;
    return head;
}

//  function insert_end, use for linklist ending insertion 
struct node * insert_end( struct node *struct_new, struct node *head, int n )
{
    struct node *temp;
    struct_new = (struct node *)malloc(sizeof(struct node));
    if( head == NULL )
    {
        head = struct_new;
        temp = head;
    }
    else{
        temp = head;
        while( temp->next != NULL ) // loop until next has NULL 
        {
            temp = temp->next;    
        }
    }
    temp->next = struct_new; 
    struct_new->data = n;
    struct_new->next = NULL;
    return head;
}

//  function insert_atany, use for linklist any-point insertion 
struct node * insert_atany( struct node *struct_new, struct node *head, int n )
{
    struct node *first;
    struct node *last;
    first = head;
    struct_new = (struct node *)malloc(sizeof(struct node));
    if( head == NULL || head->data >= n )  // check if head already NUll or input value of user need to insert at begining
    {
        struct_new->data = n;
        struct_new->next = head;
        head = struct_new;
    }
    else{
        while( first != NULL && first->data < n )  // loop until user input in greater
        {
            last = first;   // store last linklist address
            first = first->next; // store next linklist address
        }
        struct_new->data = n;
        struct_new->next = first;
        last->next = struct_new;
    }
    return head;
}

struct node * delete_data( struct node *struct_new, struct node *head,int n )
{
    struct node *temp,*tempstore;
    temp = head;
    if( head == NULL )
    {
        cout << "\n There is Nothing To Delete. \n";
    }
    else if( temp->data == n )
    {
        head = temp->next;
        free(temp);
    }
    else{
        if( temp->data != n && temp->next == NULL )
        {
            cout << "\n No Such Data To Delete. \n";
        }
        else if( temp->data == n && temp->next == NULL )
        {
            free(temp);
            head = NULL;
        }
        else{
            while( temp->next->data != n )
            {
                if( temp->next->next != NULL )
                {
                    temp = temp->next;
                }
                else{
                    cout << "\n No Such Data To Delete. \n";
                    menu(struct_new,head);
                }
            }
            tempstore = temp->next;
            temp->next = temp->next->next;
            free(tempstore);
        }
    }
    return head;
}

//  function display_link will display the linklist elements
void display_link(struct node *head)
{
    struct node *temp;
    if(head == NULL)    // check wheater the head is null
    {
        cout << "\nThere Is Nothing To Display.\n";
    }
    else
    {
        temp = head;
        cout << "\nThe List is : \n";
        while(temp->next != NULL)   // print all the elements from the link-list
        {
            cout << temp->data << " => ";
            temp = temp->next;
        }
       cout << temp->data;
    }
}

