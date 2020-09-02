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
int get_input();
void Addition_Element_linklist( struct node * );
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
        Addition_Element_linklist(head);
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
    printf("\n 1 . Input Data To Link-List. \n 2 . Display The Addition of Element from Link List. \n 3 . Display The Link List. \n 4 . Exit. \n");
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
    int i,input = get_input();
    new = (struct node *)malloc(sizeof(struct node));  
    new->data = input;
    new->next = head;
    head = new;
    return head;
}


// Function for getting input from user 
int get_input()
{
    int in;
    printf("\n Enter The Number : ");
    scanf("%d",&in);
    return in;
}


// Function to add element of the linklist
void Addition_Element_linklist( struct node *head )
{
    int sum = 0;
    struct node *temp;
    temp = head;
    while( temp != NULL )
    {
        sum += temp->data;
        temp = temp->next;
    }
    printf(" \n The Total of the All Elements : %d \n",sum);
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