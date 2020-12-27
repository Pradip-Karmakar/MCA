#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *left,*right;
};

// method declaration
void menu(struct tree *);
struct tree * construct(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
void inorder(struct tree *);
void minmax(struct tree *,int []);
void searching(struct tree *); 
bool advancesearch(struct tree *,int);
struct tree * insert(struct tree *);
struct tree * deleteNode(struct tree *,int); 
struct tree * minfromRight(struct tree * ); 

int main(){
    struct tree *head = NULL;
    menu(head);
    return 0;
}


void menu(struct tree *head) {
    int listen = 0;
    while(1){
        cout << endl << "1. Create Tree" << endl << "2. PreOrder Traversal" << endl << "3. PostOrder Traversal" << endl << "4. InOrder Traversal" << endl << "5. Insertion" << endl << "6. Searching" << endl << "7. Find Minimum & Maximum" << endl << "8. Deletion" << endl << "9. Exit"  << endl << "Enter Your Choice : ";
        cin >> listen;
        switch (listen)
        {
        case 1:
            head = construct(head); 
            break;
        case 2:
            preorder(head);
            break;
        case 3:
            postorder(head);
            break;
        case 4:
            inorder(head);
            break;
        case 5:
            head = insert(head);
            break;
        case 6:
            searching(head);
            break;
        case 7:
        {
            int m[2] = {head->data};
            minmax(head,m);
            cout << "Minimum From Tree is : " << m[0] << endl;
            cout << "Maximum From Tree is : " << m[1] << endl;
        }
        break;
        case 8:
            {
                int value;
                cout << "Enter The Number You want to delete : ";
                cin >> value; 
                head = deleteNode(head,value);
            }
            break;
        case 9:
            exit(0);
        default:
            cout << "Select Valid Options." << endl;
            menu(head);
        }
    }
}

void preorder(struct tree *head) {
    struct tree *temp;
    temp = head;
    if(temp == NULL) 
        return;

    cout << temp->data << " "; 
    preorder(temp->left);
    preorder(temp->right); 
}

void postorder(struct tree *head) {
    struct tree *temp;
    temp = head;
    if(temp == NULL) 
        return;
 
    postorder(temp->left);
    postorder(temp->right); 
    cout << temp->data << " ";
}

void inorder(struct tree *head) {
    struct tree *temp;
    temp = head;
    if(temp == NULL) 
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right); 
}

void minmax(struct tree *head,int m[]) {
    struct tree *temp;
    temp = head;
    if(temp == NULL) 
        return;

    minmax(temp->left,m);
    if(temp->data < m[0]) 
        m[0] = temp->data;
    if(temp->data > m[1])
        m[1] = temp->data;
    minmax(temp->right,m); 
}

void searching(struct tree *head) {
    bool found = false;
    int getNum;
    cout << "Enter the Number You want to find from tree : ";
    cin >> getNum;

    if(head == NULL) {
        cout << "The Tree is Empty." << endl;
        return;
    }
    found = advancesearch(head,getNum);
    if(found) 
        cout << "The Number You searching is present in the tree" << endl;
    else
        cout << "The Number You searching is not present in the tree" << endl;
}

bool advancesearch(struct tree *head,int getNum) {
    struct tree *temp;
    temp = head;
    bool found = false;
    if(temp == NULL) 
        return found;

    if(temp->data == getNum) {
        found = true;
        return found;
    }
    advancesearch(temp->left,getNum);
    advancesearch(temp->right,getNum);

    return found;
}

struct tree * construct(struct tree *head) {
    int i = 0;
    cout << "Total Data You Want : ";
    cin >> i;
    while(i > 0) {
        head = insert(head);
        i--;
    }
    return head;
}

struct tree * insert(struct tree *head) {
    bool target = false;
    int input;
    struct tree *n,*temp;
    temp = head;
    cout << "Enter Value : ";
    cin >> input;
    n = (struct tree *)malloc(sizeof(struct tree));

    if(head == NULL){
        head = n;
    }
    else {
        while(!target) {
            if(temp->data > input && temp->left != NULL){
                temp = temp->left;
            }
            else if(temp->data < input && temp->right != NULL ) {
                temp = temp->right;
            }

            if((temp->data < input && temp->right == NULL) || (temp->data > input && temp->left == NULL)) {
                target = true;
            }
        }
        if(temp->data < input) {
            temp->right = n; 
        }
        else {
            temp->left = n;
        }
    }
    n->data = input;
    n->left = n->right = NULL;
    return head;
}

struct tree * deleteNode(struct tree* head, int deletethis) { 
    struct tree *temp;
    temp = head;
    if (temp == NULL) 
        return temp; 
  
    if (deletethis < temp->data) 
        temp->left = deleteNode(temp->left, deletethis); 
  
    else if (deletethis > temp->data) 
        temp->right = deleteNode(temp->right, deletethis); 
  
    else
    {  
        if (temp->left == NULL) 
        { 
            struct tree *temp2 = temp->right; 
            free(temp); 
            return temp2; 
        } 
        else if (temp->right == NULL) 
        { 
            struct tree *temp2 = temp->left; 
            free(temp); 
            return temp2; 
        } 
   
        struct tree* temp2 = minfromRight(temp->right); 
  
        temp->data = temp2->data; 
  
        temp->right = deleteNode(temp->right, temp2->data); 
    } 
    return temp; 
} 

struct tree * minfromRight(struct tree* temp) { 
    struct tree* current = temp; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 