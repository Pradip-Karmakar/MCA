#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// stucture defination
struct node {
   struct node *left;
   int num;
   struct node *right;
};

// Functions declaration
struct node *newNode(int);
void InOrderTraversal(struct node *);
struct node* getNode(struct node *, int);

// Main Function
void main() {
   struct node *data = NULL;
   int count,number;
   for( count = 1; count < 11; count++ )
   {
      printf("Enter No-%d : ",count);
      scanf("%d",number);
      if(data == NULL)
      {
         data = getNode(data, number);  // setting data as a root node, all traversal will be done from here
      }
      else{
         getNode(data, number);
      }
   }
   printf("After Converting In-Order Traversal : ");
   InOrderTraversal(data); // set the tree in Inorder binary search tree
}

// Function for creating new node with left and right pointer to structure
struct node *newNode(int number) {
   struct node *temp; 
   temp = (struct node *)malloc(sizeof(struct node));
   temp->num = number;
   temp->left = temp->right = NULL;
   return temp;
}

// Function for checking the value, if the node should be left or right child.
struct node* getNode(struct node* node, int number) {
   if (node == NULL) 
   {
      return newNode(number);
   }
   if (node->num > number)
   {
      node->left = getNode(node->left, number);
   }
   
   else if (node->num < number)
   {
      node->right = getNode(node->right, number);
   }
   
   return node;
}

// Print the values in In-order Traversal 
void InOrderTraversal(struct node *root) {
   if (root != NULL) {
      InOrderTraversal(root->left);
      printf("\n%d",root->num);
      InOrderTraversal(root->right);
   }
}



// void postfixTree(struct node *head){
//    struct node *temp,*tree,*traversal;
//    temp = head;
//    while(temp != NULL)
//    {
//       if(temp->data == '+' || temp->data == '-' || temp->data == '/' || temp->data == '*')
//       {
//           tree = (struct node *)malloc(sizeof(struct node));
//          tree->data = temp->data;
//          tree->right = temp->left;
//          tree->left = temp->left->left;
//       }
//       temp = temp->right;
//    }
// }