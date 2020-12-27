#include<iostream>
using namespace std;

class circular{
    public:
        int check(int value){
            return value < 5 ? 1:0;
        }   
};

int main()
{
    circular c;
    int a = 7,b;
    b = c.check(a);
    cout << b;
    return 0;
}












// struct node * insert_end( struct node *new, struct node *head, struct node *tail )
// {
//     int n = get_n();
//     struct node *temp;
//     temp = head;
//     new = (struct node *)malloc(sizeof(struct node));
//     if(head == NULL)
//     {
//         new->prev = NULL;
//         new->data = n;
//         new->next = NULL;
//         head = new;
//         tail = new;
//     }
//     else{
//         if(temp->next != NULL)
//         {
//             while(temp->next != head)
//             {
//                 temp = temp->next;
//             }
//             temp->next = new;
//         }
//     }
//     new->prev = tail;
//     new->data = n;
//     new->next = head;
//     head->prev = new;
//     tail = new;

//     return tail;
// }