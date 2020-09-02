#include<stdio.h>   //c standard library
#include<conio.h>   //c input ouput library
#include<stdlib.h>  //c stdlib Library file

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
void main()
{
    struct node *new;
    struct node *head = NULL;
    menu(new,head); // Calling menu funtion
}

// menu function
void menu( struct node *new, struct node *head )
{
    int n,getnum;
    printf("\n 1 . Add New Data To Linklist From Begining. \n 2 . Add New Data To Linklist From Ending.\n 3 . Add New Data To Linklist At Any Place. \n 4 . Delete a Number From The Link-List. \n 5 . Display LinkList Till Now. \n 6 . Exit. \n");
    scanf("%d",&n);
    // Switch case which check the user input and run specified function
    switch(n)
    {
        case(1):
            getnum = get_n('i');
            head = insert_beg(new,head,getnum);   //insertion from begining linklist function call 
            menu(new,head);    //void menu function call
        case(2):
            getnum = get_n('i');
            head = insert_end(new,head,getnum);   //insertion from ending linklist function call 
            menu(new,head);    //void menu function call
        case(3):
            getnum = get_n('i');
            head = insert_atany(new,head,getnum);   //insertion from any point linklist function call 
            menu(new,head);    //void menu function call
        case(4):
            getnum = get_n('d');
            head = delete_data(new,head,getnum);
            menu(new,head);
        case(5):
            display_link(head);     //display linklist function call 
            menu(new,head);     //void menu function call
        case(6):
            exit(0);    //exit function call which terminated the program
        default:
            printf("\n Please Enter Valid Number.");
            menu(new,head);     //void menu function call
    }
}

// function for taking input from user

int get_n(char a)
{
    int n;
    if( a == 'i' )
    {
        printf(" Enter The Number : ");
    }
    else{
        printf(" Enter The Number to Delete : ");
    }
    scanf("%d",&n);
    return n;
}

//  function insert_beg, use for linklist begining insertion 
struct node * insert_beg( struct node *new, struct node *head,int n )
{
    new = (struct node *)malloc(sizeof(struct node));  
    new->data = n;
    new->next = head;
    head = new;
    return head;
}

//  function insert_end, use for linklist ending insertion 
struct node * insert_end( struct node *new, struct node *head, int n )
{
    struct node *temp;
    new = (struct node *)malloc(sizeof(struct node));
    if( head == NULL )
    {
        head = new;
        temp = head;
    }
    else{
        temp = head;
        while( temp->next != NULL ) // loop until next has NULL 
        {
            temp = temp->next;    
        }
    }
    temp->next = new; 
    new->data = n;
    new->next = NULL;
    return head;
}

//  function insert_atany, use for linklist any-point insertion 
struct node * insert_atany( struct node *new, struct node *head, int n )
{
    struct node *first;
    struct node *last;
    first = head;
    new = (struct node *)malloc(sizeof(struct node));
    if( head == NULL || head->data >= n )  // check if head already NUll or input value of user need to insert at begining
    {
        new->data = n;
        new->next = head;
        head = new;
    }
    else{
        while( first != NULL && first->data < n )  // loop until user input in greater
        {
            last = first;   // store last linklist address
            first = first->next; // store next linklist address
        }
        new->data = n;
        new->next = first;
        last->next = new;
    }
    return head;
}

struct node * delete_data( struct node *new, struct node *head,int n )
{
    struct node *temp,*tempstore;
    temp = head;
    if( head == NULL )
    {
        printf("\n There is Nothing To Delete. \n");
    }
    else if( temp->data == n )
    {
        head = temp->next;
        free(temp);
    }
    else{
        if( temp->data != n && temp->next == NULL )
        {
            printf("\n No Such Data To Delete. \n");
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
                    printf("\n No Such Data To Delete. \n");
                    menu(new,head);
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
        printf("\nThere Is Nothing To Display.\n");
    }
    else
    {
        temp = head;
        printf("\nThe List is : \n");
        while(temp->next != NULL)   // print all the elements from the link-list
        {
            printf(" %d => ",temp->data);
            temp = temp->next;
        }
        printf(" %d \n",temp->data);
    }
}
