#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//Drosais datu ievads mezglam
int safeInputNode(Node *newNode) {
    while (true) {
        cout << "Enter the number to add: ";
        cin >> newNode->data;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nYou entered incorrect data, please try again!\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return newNode->data;
        }
    }
}

//Drosais datu ievads int
int safeInputInt() {
    int value;
    while (true) {
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input, please enter a number!\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


//Create Node
Node *createNode(){
    Node *newNode;
    newNode=new Node;
    safeInputNode(newNode);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}


//Ekrana tirisana
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void pauseScreen() {
    cout << "\nPlease click 'Enter' to continue\n";;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printTree(Node *cur){
    if(!cur) return;
    printTree (cur->left);
    cout<<cur->data;
    printTree(cur->right);
}

Node *addNode(Node *root){
    Node *newNode, *cur;
    newNode=createNode();
    if(!root){
        root=newNode;
    } else {
    while(cur->left!=NULL && cur->data>newNode->data || (cur->right!=NULL && cur->data<=newNode->data)){
        while (cur->left!=NULL && cur->data>newNode->data)
        {
            cur=cur->left;
        }

        while (cur->right!=NULL && cur->data<=newNode->data)
        {
            cur=cur->right;
        }
        

        if(cur->data>newNode->data){
            cur->left=newNode;
        } else cur->right=newNode;
    }
        
    }
    return root;
}

int main(){
    Node *root=NULL; //adrese tipa Node, kura saucas head
    int choice;

    do
    {
        clearScreen();
        cout<<"\nAutors: Vladlena Klimova\n";
        cout<<"\nSelect action: ";
        cout<<"\n1. Creating and outputting the root of a tree";
        cout<<"\n2. Adding an element";
        cout<<"\n3. Searching for an element";
        cout<<"\n4. Deleting an element";
        cout<<"\n5. Printing the tree.";
        cout<<"\n6. Traversing the tree (preorder, inorder, postorder)";
        cout<<"\n7. Determining the number of elements";
        cout<<"\n8. Rotating the tree";
        cout<<"\n9. Finish the program";//

        cout << "\nSelect action: ";
        choice=safeInputInt();

        switch (choice)
        {
        case 1:
            if(!root){
                root=createNode();
            } else{
                cout<<"\nRoot already exists: "<<root->data;
                cout<<endl;
            }
            break;
        
        case 2:
            if(!root){
               root=createNode();
            } else{
                root=addNode(root);
                printTree(root);
            }
        break;

        case 3:
        if(!root){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            // head=addDataEnd(head);
            // head=listOutput(head);
        }
        break;

        case 4:
        if(!root){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            // head=addDataAfter(head);
            // head=listOutput(head);
        }
        break;

        case 5:
        if(!root){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            // head=addDataBefore(head);
            // head=listOutput(head);
        }
        break;

        case 6:
        if(!root){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            // head=deleteFirst(head);
            // head=listOutput(head);
        }
        break;

        case 7:
        if(!root){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            // head=deleteLast(head);
            // head=listOutput(head);
        }
        break;

        case 8:
        if(!root){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            // head=deleteAfterSel(head);
            // head=listOutput(head);
        }
        break;
        
        case 9:
        cout<<"\nThe program is over!\n";
        break;

        default: 
        cout<<"\nYou entered incorrect data, please try again!\n";
            break;
        }
        if(choice!=9) pauseScreen();
    } while (choice!=9);

    return 0;
}