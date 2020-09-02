#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
  int data;     //data part of list.
  struct node *nxtVarAdd;     //the pointr which will contain the address of other list.

}*head=NULL,*new1,*new2,*temp,*new3,*temp1,*temp2;

void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void display();

void main()
{
  int n;
  while(1)
  {
    x:
    printf("\tLinked List Operation.\n");
    printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
    printf("\nSELECT LLO OPTION : ");
    scanf("%d",&n);
    switch(n)
    {
      case 1:
       y:
       printf("\n\tINSERT MENU.");
       printf("\n1. INSERT AT BEGINING.\n2. INSERT AT POSITION.\n3. INSERT AT END.\n4. BACK.\n5. EXIT.\n");
       printf("SELECT INSERT OPTION : ");
       scanf("%d",&n);
       switch(n)
       {
	case 1:
	 insert_beg();
	 break;
	case 2:
	 insert_pos();
	 break;
	case 3:
	 insert_end();
	 break;
	case 4:
	 goto x;
	case 5:
	 exit(0);
	default:
	 printf("\n!!!!Please SELECT Correct Option.!!!!\n");
	 goto y;
       }
       break;

      case 2:
       z:
       printf("\n\tDELETE Menu.");
       printf("\n1. DELETE AT BEGINING.\n2. DELETE AT POSITION.\n3. DELETE AT END.\n4. BACK. \n5. EXIT.\n");
       printf("SELECT DELETE OPTION : ");
       scanf("%d",&n);
       switch(n)
       {
	case 1:
	 del_beg();
	 break;
	case 2:
	 del_pos();
	 break;
	case 3:
	 del_end();
	 break;
	case 4:
	 goto x;
	case 5:
	 exit(0);
	default:
	 printf("\n!!!!Please SELECT Correct Option.!!!!\n");
	 goto z;
       }

       break;

      case 3:
       display();
       break;
      case 4:
       exit(0);//succesful termination of program.
      default:
       printf("\n!!!!Please SELECT Correct Option.!!!!\n");
       goto x;
    }
  }

}


void insert_beg()
{
   int n;
   new1 = (struct node*)malloc(sizeof(struct node));
   printf("\nEnter Number : ");
   scanf("%d",&n);
   new1->data = n;

   if(head == NULL)
   {
     new1->nxtVarAdd = NULL;
     head = new1;
   }
   else
   {
     new1->nxtVarAdd = head;
     head = new1;
   }

}

void insert_end()
{
  int n;
  new2 = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter Number : ");
  scanf("%d",&n);
  new2->data = n;
  new2->nxtVarAdd = NULL;

  if(head == NULL)
  {

    head = new2;
  }
  else
  {
    temp = head;
    while(temp->nxtVarAdd != NULL)
    {
       temp = temp->nxtVarAdd;
    }
    temp->nxtVarAdd = new2;

  }
}

void insert_pos()
{
  int n,pos,i;

  printf("\nEnter Position To Insert Number : ");
  scanf("%d",&pos);


  if(pos == 1)
  {
     insert_beg();
  }
  else
  {
    new3 = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Number : ");
    scanf("%d",&n);
    new3->data = n;

    temp = head;

    for(i=0;i<pos-2;i++)
    {
      if(temp->nxtVarAdd == NULL)
      {
	printf("\n!!! There Are Less Nodes !!!\n");
	break;
      }
      temp = temp->nxtVarAdd;
    }

    new3->nxtVarAdd = temp->nxtVarAdd;
    temp->nxtVarAdd = new3;

  }
}

void del_beg()
{
  if(head == NULL)
  {
    printf("\nNO List to Delete");
  }
  else if(head->nxtVarAdd == NULL)
  {
    printf("\nDeleted List Element Is %d.",head->data);
    free(head);
    head = NULL;
  }
  else
  {
    temp = head;
    head = head->nxtVarAdd;
    printf("\nDeleted List Element Is %d.",temp->data);
    free(temp);
    temp = NULL;

  }

}

void del_end()
{
  if(head == NULL)
  {
     printf("\n!!! NO List to Delete !!!");
  }
  else if(head->nxtVarAdd == NULL)
  {
    printf("\nDeleted List Element Is %d.",head->data);
    free(head);
    head = NULL;

  }
  else
  {
     temp = head;
     while(temp->nxtVarAdd->nxtVarAdd != NULL)
     {
       temp = temp->nxtVarAdd;

     }
     temp1 = temp->nxtVarAdd;
     temp->nxtVarAdd = NULL;

     printf("\nDeleted List Element Is %d.",temp1->data);
     free(temp1);
     temp1 = NULL;

  }
}

void del_pos()
{
  int pos,i;
  printf("\nEnter Position To Delete Number : ");
  scanf("%d",&pos);

  if(pos == 1)
  {
    del_beg();
  }
  else if(head->nxtVarAdd == NULL && pos >= 2)
  {
    printf("\n!!! There Are Less Nodes !!!");

  }
  else
  {
    temp = head;
    for(i=0;i<pos-2;i++)
    {
      if(temp->nxtVarAdd->nxtVarAdd == NULL)
      {
	 printf("\n!!! There Are Less Nodes !!!");
	 break;
      }
      temp = temp->nxtVarAdd;
    }
    temp2 = temp->nxtVarAdd;
    temp->nxtVarAdd = temp2->nxtVarAdd;

    printf("\nDeleted List Element Is %d.",temp2->data);
    free(temp2);
    temp2 = NULL;
  }
}

void display()
{
  if(head == NULL)
  {
    printf("\nThere Is Nothing To Display.");

  }
  else
  {
    temp = head;
    printf("\nThe List is : \n");
    while(temp->nxtVarAdd != NULL)
    {
      printf(" %d => ",temp->data);
      temp = temp->nxtVarAdd;
    }
    printf(" %d => \n",temp->data);
  }
}