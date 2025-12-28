#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void rotateTree(Node *root);

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
Node *createNode(int &elCount){
    elCount+=1;
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
    cout<<cur->data<<" ";
    printTree(cur->right);
}

//Adding an element
Node *addElement(Node *root, int &elCount){

    Node *newNode, *cur;
    cur=root;
    newNode=createNode(elCount);
    while (true)
    {
        if(cur->data>newNode->data){
            if(cur->left==NULL){
                cur->left=newNode;
                return root;
            } else cur=cur->left;
        } else{
            if(cur->right==NULL){
                cur->right=newNode;
                return root;
            } else cur=cur->right;
        }
    }

    return root;
}

//Searching for an element
void search(Node *root){
    cout<<"\nYour elements: ";
    printTree(root);

    cout<<"\nPut which element to search: ";
    int choice=safeInputInt();

    Node *cur;
    cur=root;

    while (cur != NULL && cur->data != choice)
    {
        if (choice < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur == NULL)
        cout << "\nThe element wasn't found!\n";
    else
        cout << "\nThe element was found!\n";
    
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
} //atrast minimalo elementu ja ir 2 berni

//Deleting an element
Node* deleteAnElement(Node *root, int inputElement, int &elCount){

    if (root == NULL ) return NULL; 
    if (inputElement < root->data) root->left = deleteAnElement(root->left, inputElement, elCount);
    else if (inputElement > root->data) root->right = deleteAnElement(root->right, inputElement, elCount);
    else {
        // mezgls ir atrasts
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //ja ir 2 berni
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteAnElement(root->right, temp->data, elCount);
    }

    return root;
    
}

//Preorder
void preorder(Node *cur){
    if(!cur) return;
    cout << cur->data << " ";
    preorder(cur->left);
    preorder(cur->right);
}

//Postorder
void postorder(Node *cur){
    if(!cur) return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->data << " ";
}

//Determining the number of elements
void elementCount(int &elCount){
    cout<<"\nYou have "<<elCount<<" elements in your tree";
}

//Rotating the tree
void rotateTree(Node *root){
    if (root == NULL) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    rotateTree(root->left);
    rotateTree(root->right);
}

int main(){
    Node *root=NULL; //adrese tipa Node, kura saucas head
    int choice;
    int elCount=0;
    int rotate = 0;

    do{
        clearScreen();
        cout<<"\nAutors: Vladlena Klimova\n";
        cout<<"\nSelect action: ";
        cout<<"\n1. Creating and outputting the root of a tree";//
        cout<<"\n2. Adding an element";//
        cout<<"\n3. Searching for an element";//
        cout<<"\n4. Deleting an element";//
        cout<<"\n5. Printing the tree";//
        cout<<"\n6. Traversing the tree (preorder, inorder, postorder)";//
        cout<<"\n7. Determining the number of elements";//
        cout<<"\n8. Rotating the tree";
        cout<<"\n9. Finish the program";//

        cout << "\nSelect action: ";
        choice=safeInputInt();

        switch (choice)
        {
        case 1:
            if(!root){
                root=createNode(elCount);
            } else{
                cout<<"\nRoot already exists: "<<root->data;
                cout<<endl;
            }
        break;

        case 2:
            if(!root){
                cout<<"\nYou don't have a root! Please, enter a number!\n";
                root=createNode(elCount);
            } else{
                    
            if(rotate%2!=0){
                rotateTree(root);
            }
                root=addElement(root, elCount);

                if(rotate%2!=0){
                    rotateTree(root);
                }
                cout<<"\nYour elements: ";
                printTree(root);
            }
        break;

        case 3:
            if(!root){
                cout<<"\nYou don't have a root! Please, enter a number!\n";
                root=createNode(elCount);
            } else{
                search(root);
            }
        break;

        case 4:
            if(!root){
                cout<<"\nYou don't have any elements!";
            } else {
                cout<<"\nYour elements: ";
                printTree(root);
                int inputElement;
                cout<<"\nWhich element do you want to delete: ";
                inputElement = safeInputInt();

                if(rotate%2!=0){
                    rotateTree(root);
                }
                root = deleteAnElement(root, inputElement, elCount);

                if(rotate%2!=0){
                    rotateTree(root);
                }
                elCount-=1;
                cout<<"\nYour elements: ";
                printTree(root);
            }
        break;

        case 5:
        if(!root){
            cout<<"\nYou don't have a root! Please, enter a number!\n";
            root=createNode(elCount);
        } else{
            cout<<"\nYour elements: ";
            printTree(root);
        }
        break;

        case 6:
        if(!root){
            cout<<"\nYou don't have a root! Please, enter a number!\n";
            root=createNode(elCount);
        } else {
            cout<<"\nYour elements (Inorder): ";
            printTree(root);
            cout<<"\nYour elements (Preorder): ";
            preorder(root);
            cout<<"\nYour elements (Postorder): ";
            postorder(root);
        }
        break;

        case 7:
            elementCount(elCount);
        break; 

        case 8:
            if(!root){
                cout<<"\nYou don't have a root! Please, enter a number!\n";
                root=createNode(elCount);
            } else {
                rotateTree(root);
                rotate+=1;
                cout << "\nThe tree has been rotated!\n";
                cout<<"\nYour elements: ";
                printTree(root);              
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