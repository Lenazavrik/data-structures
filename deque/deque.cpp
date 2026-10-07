#include <iostream>
#include <cstdlib>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node *prev;
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

//Ekrana tirisana
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void pauseScreen() {
    cout << "\nPlease click 'Enter' to continue\n";;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Create Node
Node *createNode(){
    Node *newNode;
    newNode=new Node;
    safeInputNode(newNode);
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

//Output all elements from the deck
Node *output(Node *left){
    Node *cur;
    cur=left;
    cout<<"\nYour list elements: ";
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
    return left;
}

//Counting all elements in a deck
Node *coutOfEl(Node *left){
    Node *cur;
    int count=0;
    cur=left;
    while (cur!=NULL)
    {
        cur=cur->next;
        count++;
    }

    cout<<"\nIt is "<<count<<" elements on deck!\n";
    return left;
    
}

//Delete all elements
Node *deleteAllDeck(Node *&left, Node *&right){
    Node *cur, *prev;
    cur=left;
    while (cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
        delete prev;
    }
    left=NULL;
    right=NULL;
    cout<<"\nAll elements are deleted!";
    return NULL;
}

//Adding an element to the beginning of a deck
Node *addElBeg(Node *&left, Node *&right){
    Node *cur, *newNode;
    if(!left){
        newNode=createNode();
        left=right=newNode;
        return left;
    }

    cur=left;
    newNode=createNode();
    newNode->next=cur;
    left->prev=newNode;
    left=newNode;
    return left;
}

//Adding an element to the end of a deck
Node *addElLast(Node *&left, Node *&right){
    Node *newNode;
    if(!right){
        newNode=createNode();
        left=right=newNode;
        return right;
    }

    newNode=createNode();
    right->next=newNode;
    newNode->prev=right;
    right=newNode;
    return right;
}

//Deleting an element at the beginning of a deck
Node *removeFirst(Node *&left, Node *&right){
    Node *remove;

    remove=left;

    if(left==right){
        delete remove;
        left=right=NULL;
        cout<<"\nFirst element is deleted!";
        return NULL;
    }

    left=left->next;
    left->prev=NULL;
    delete remove;
    cout<<"\nFirst element is deleted!";
    return left;
}

//Deleting an element at the end of a deck
Node *removeLast(Node *&left, Node *&right){
    Node *remove;

    remove=right;

    if(left==right){
        delete remove;
        left=right=NULL;
        cout<<"\nFirst element is deleted!";
        return NULL;
    }

    right=right->prev;
    right->next=NULL;
    delete remove;
    cout<<"\nFirst element is deleted!";
    return right;
}

int main(){
    Node *left=NULL, *right=NULL;
    int choice;
        do
    {
        clearScreen();
        cout<<"\nAutors: Vladlena Klimova, 09.10.25\n";
        cout<<"\nSelect action: ";
        cout<<"\n1. Adding an element to the beginning of a deck";//
        cout<<"\n2. Adding an element to the end of a deck";//
        cout<<"\n3. Deleting an element at the beginning of a deck";//
        cout<<"\n4. Deleting an element at the end of a deck";
        cout<<"\n5. Output all elements from the deck";//
        cout<<"\n6. Counting all elements in a deck";//
        cout<<"\n7. Delete all elements";//
        cout<<"\n8. Finish the program";//

        
        cout << "\nSelect action: ";
        choice=safeInputInt();
        switch (choice)
        {
        case 1:
            left=addElBeg(left, right);
            left=output(left);
        break;

        case 2:
        right=addElLast(left, right);
        left=output(left);
        break;

        case 3:

        if(!left){
        cout<<"\nYou don't have any elements! Please select 1 or 2 action!";
        } else {
            left=removeFirst(left, right);
            left=output(left);
        }
        break;

        case 4:
        if(!right){
        cout<<"\nYou don't have any elements! Please select 1 or 2 action!";
        } else{
            right=removeLast(left, right);
            left=output(left);
        }
        break;

        case 5:
            if(!left && !right){
                cout<<"\nYou don't have any elements! Please select 1 or 2 action!";
            } else {
            left=output(left);
            }
        break;

        case 6:
        left=coutOfEl(left);
        break;

        case 7:
        if(!left){
            cout<<"\nYou don't have any elements! Please select 1 or 2 action!";
        } else{
            left=deleteAllDeck(left, right);
        }
        break;

        case 8:
        cout<<"\nThe program is over!\n";
        break;
        
        default: cout<<"\nYou entered incorrect data, please try again!\n";
            break;
        }

    if(choice!=8) pauseScreen();
    } while (choice!=8);
    return 0;
}