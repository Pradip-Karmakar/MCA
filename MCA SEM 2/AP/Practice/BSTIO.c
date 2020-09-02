#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

// stucture defination
struct node {
   struct node *left;
   char string[15];
   struct node *right;
};

// Functions declaration
struct node *newNode(char []);
void InOrderTraversal(struct node *);
struct node* getNode(struct node *, char[]);

// Main Function
void main() {
   struct node *data = NULL;
   int count;
   char name[15];
   for( count = 1; count < 11; count++ )
   {
      if(data == NULL)
      {
         printf("Enter Word No-%d : ",count);
         scanf("%s",name);
         data = getNode(data, name);  // setting data as a root node, all traversal will be done from here
      }
      else{
         printf("Enter Word No-%d : ",count);
         scanf("%s",name);
         getNode(data, name);
      }
   }
   printf("After Converting In-Order Traversal : ");
   InOrderTraversal(data); // set the tree in Inorder binary search tree
}

// Function for creating new node with left and right pointer to structure
struct node *newNode(char value[]) {
   struct node *temp; 
   temp = (struct node *)malloc(sizeof(struct node));
   strcpy(temp->string,value);
   temp->left = temp->right = NULL;
   return temp;
}

// Function for checking the value, if the node should be left or right child.
struct node* getNode(struct node* node, char value[]) {
   int check;
   if (node == NULL) 
   {
      return newNode(value);
   }
   check = strcmp(node->string, value);
   if (check > 0)
   {
      node->left = getNode(node->left, value);
   }
   
   else if (check < 0 || check == 0)
   {
      node->right = getNode(node->right, value);
   }
   
   return node;
}

// Print the values in In-order Traversal 
void InOrderTraversal(struct node *root) {
   if (root != NULL) {
      InOrderTraversal(root->left);
      printf("\n%s",root->string);
      InOrderTraversal(root->right);
   }
}
