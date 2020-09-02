#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int ask_selection();
void menu( struct node *, struct node * );
struct node * get_link_list( struct node *, struct node * );
int get_input();
void display(struct node *);

void main()
{
    struct node *new,*head = NULL;    
    menu(new,head);
}



void menu(struct node *new,struct node *head)
{
    int selection = ask_selection();
    switch (selection)
    {
    case(1):
        head = get_link_list(new,head);
        menu(new,head);
    case(2):
        display(head);
        menu(new,head);    
    default:
        exit(0);
    }
}



int ask_selection()
{
    int n;
    printf("\n 1 . Input Data To Link-List. \n 2 . Display The Link List in LIFO. \n 3 . Exit. \n");
    scanf(" %d",&n);
    if( n > 0 && n < 4 )
    {
        return n;
    }
    else{
        printf("\n Wrong Selection Please Choose Correct Options. \n");
        ask_selection();
    }
}



struct node * get_link_list( struct node *new, struct node *head )
{
    int input = get_input();
        new = (struct node *)malloc(sizeof(struct node));  
        new->data = input;
        new->next = head;
        head = new;
    return head;
}



int get_input()
{
    int in;
    printf("\n Enter The Number : ");
    scanf("%d",&in);
    return in;
}



void display(struct node *head)
{
    int count = 0;
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
            count++;
        }
        printf(" %d \n Total Data Found : %d",temp->data, count+1);
    }
}