#include<iostream>
using namespace std;
int queue[5],front = 0,rear = 0;


void insert()
{
    if(rear == 5)
    {
        printf("\nQueue is Full");
    }
    else
    {
        int data;
        printf("\nEnter the data : ");
        scanf("%d",&data);
        queue[rear] = data;
        rear++;
    }
    
}
void delete1()
{
    if(front == 0 && rear == 0)
    {
        printf("\nQueue is Empty!!");
    }
    else
    {
        printf("\nElement deleted");
        for(int i=0;i<rear-1;i++)
        {
            queue[i]=queue[i+1];
            
        }
        rear--;
    }
    
}
void display()
{
    if(front == 0 && rear == 0)
    {
        printf("\nQueue is Empty!!");
    }
    else
    {   
        printf("\n Elements in Queue");
        for(int i = 0;i<rear;i++)
        printf("\n%d",queue[i]);
    }
       
}


int main()
{
   int option;
   for(;;)
   {
       printf("\n\n1. Insert Element in Queue");
       printf("\n2. Delete element in Queue");
       printf("\n3. Display the element in Queue\n");
       scanf("%d",&option);
       switch (option)
       {
           case 1:
                insert();
                break;
            case 2:
                delete1();
                break;
            case 3:
                display();
                break;
            default:
                printf("\n Invalid !!!");

       } 
   }

}