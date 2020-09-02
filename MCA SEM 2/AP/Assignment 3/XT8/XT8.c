#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Structure Declaration
struct node{
    int data;
    struct node *next;
};


// Functions Declaration
void menu( struct node *, struct node * );
int ask_selection();
struct node * get_linklist( struct node *, struct node * );
int get_input(int);
void Swap_Element_linklist( struct node * );
void display_linklist(struct node *);


// Main Function 
void main()
{
    struct node *new,*head = NULL;
    menu(new,head);
}


// Menu Function
void menu(struct node *new,struct node *head)
{
    int selection = ask_selection();
    switch (selection)
    {
    case(1):
        head = get_linklist(new,head);
        menu(new,head);
    case(2): 
        Swap_Element_linklist(head);
        menu(new,head);
    case(3):
        display_linklist(head);
        menu(new,head);    
    default:
        exit(0);
    }
}


// ask_selection Function
int ask_selection()
{
    int n;
    printf("\n 1 . Input Data To Link-List. \n 2 . Swap The Consecutive Values. \n 3 . Display The Link List. \n 4 . Exit. \n");
    scanf(" %d",&n);
    if( n > 0 && n < 5 )
    {
        return n;
    }
    else{
        printf("\n Wrong Selection Please Choose Correct Options. \n");
        ask_selection();
    }
}


// getting elements to linklist with reverse functionality Function
struct node * get_linklist( struct node *new, struct node *head )
{
    int i,input = get_input(0);
    new = (struct node *)malloc(sizeof(struct node));  
    new->data = input;
    new->next = head;
    head = new;
    return head;
}


// Function for getting input from user 
int get_input(int a)
{
    int in;
    if( a == 0 )
    {
        printf("\n Enter The Number : ");
    }
    else{
        printf("\n Enter The Swapping Number : ");
    }
    scanf("%d",&in);
    return in;
}


// Function to add element of the linklist
void Swap_Element_linklist( struct node *head )
{
    int swap_me = get_input(1),temp_hold = 0;
    struct node *temp;
    temp = head;
    while( temp != NULL && temp->data != swap_me )
    {
        temp = temp->next;
    }
    if( temp == NULL || temp->next == NULL )
    {
        printf("\n Swapping Not Possible. \n");
    }
    else{
        temp_hold = temp->data;
        temp->data = temp->next->data;
        temp->next->data = temp_hold;
        printf(" \n Swapping Done. \n");
    }
}


// Funtion Display will show all elements in linklist
void display_linklist(struct node *head)
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nThere Is Nothing To Display.\n");
    }
    else
    {
        temp = head;
        printf("\nThe List is : \n");
        while(temp->next != NULL)
        {
            printf(" %d => ",temp->data);
            temp = temp->next;
        }
        printf(" %d \n",temp->data);
    }
}