#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int N;
    int *Ranks;
    int *gifts;
    struct node *next;
};


int get_data();
void get_input( int, struct node *, struct node * );


int main()
{
    int T;
    struct node *data,*head = NULL;
    T = get_data();
    get_input(T,data,head);
    return 0;
}

int get_data(){
    int d;
    scanf("%d",&d);
    return d;
}

void get_input( int T, struct node *data, struct node *head )
{
    int employee = 0, i, j = 0, max = pow(10,9), result[9], total;
    while( T != 0 )
    {
        data = (struct node *)malloc(sizeof(struct node));
        data->N = get_data();
        employee = data->N;
        if( employee > 1 && employee < 100000 )
        {
            i = 0;
            total = 0;
            while( employee != 0 )
            {
                data->Ranks = (int *)malloc(sizeof(int));
                scanf("%d",data->Ranks[i]);
                if( data->Ranks[i] < 1 && data->Ranks[i] > max )
                {
                    exit(0);
                }
                else{
                    data->gifts = (int *)malloc(sizeof(int));
                    if( i = 0 )
                    {
                        data->gifts[i] = 1;
                        total += 1;
                    }
                    else{
                        if( data->Ranks[i] > data->Ranks[i-1] )
                        {
                            data->gifts[i] = data->gifts[i-1] + 1;
                            total += data->gifts[i];
                        }
                        else if( data->Ranks[i] < data->Ranks[i-1] && i != 1)
                        {
                            data->gifts[i] = data->gifts[i-1] - 1;
                            total += data->gifts[i];
                        }
                        else{
                            data->gifts[i] = data->gifts[i-1];
                            total += data->gifts[i];
                        }
                    }
                }
                --employee;
                ++i;
            }
            result[j] = total;
            ++j;
        }
        data->next = head;
        head = data;
        --T;
    }
    j = 0;
    while( j != T-1 )
    {
        printf("%d\n",result[j]);
        ++j;
    }
}
