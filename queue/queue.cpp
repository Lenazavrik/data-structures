#include <iostream>
#include <cstdlib>
using namespace std;

struct  Node
{
    int data;
    Node *link;
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
    newNode->link=NULL;
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

//Add an element to the end of the queue
Node *addEl(Node *head){
    Node *cur, *newNode;
    if(!head){
        newNode=createNode();
        head=newNode;
        return head;
    }

    cur=head;
    while (cur->link!=NULL)
    {
        cur=cur->link;
    }
    
    newNode=createNode();
    cur->link=newNode;
    return head;
}

//Output all elements from the queue
Node *output(Node *head){
    Node *cur;
    cur=head;
    cout<<"\nYour list elements: ";
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur=cur->link;
    }
    cout<<endl;
    return head;
}

//Remove an element from the front of the queue
Node *removeFirst(Node *head){
    Node *cur, *remove;

    if(head->link==NULL){
        delete head;
        cout<<"\nFirst element is deleted!";
        return NULL;
    }

    cur=head;
    remove=cur;
    head=cur->link;
    delete remove;
    cout<<"\nFirst element is deleted!";
    return head;
}

//Counting all elements in a queue
Node *coutOfEl(Node *head){
    Node *cur;
    int count=0;
    cur=head;
    while (cur!=NULL)
    {
        cur=cur->link;
        count++;
    }

    cout<<"\nIt is "<<count<<" elements on stack!\n";
    return head;
    
}

//Delete all elements
Node *deleteAllStack(Node *head){
    Node *cur, *prev;
    cur=head;
    while (cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
        delete prev;
    }
    head=NULL;
    cout<<"\nAll elements are deleted!";
    return head;
}

int main(){
    Node *head=NULL;
    int choice;
    do
    {
        clearScreen();
        cout<<"\nAutors: Vladlena Klimova, 09.10.25\n";
        cout<<"\nSelect action: ";
        cout<<"\n1. Add an element to the end of the queue";//
        cout<<"\n2. Remove an element from the front of the queue";
        cout<<"\n3. Output all elements from the queue";//
        cout<<"\n4. Counting all elements in a queue";//
        cout<<"\n5. Delete all elements";//
        cout<<"\n6. Finish the program";//

        
        cout << "\nSelect action: ";
        choice=safeInputInt();
        switch (choice)
        {
        case 1:
            head=addEl(head);
            head=output(head);
        break;

        case 2:

        if(!head){
        cout<<"\nYou don't have any elements! Please select 1 action!";
        } else {
            head=removeFirst(head);
            head=output(head);
        }
        break;

        case 3:
            if(!head){
        cout<<"\nYou don't have any elements! Please select 1 action!";
            } else {
            head=output(head);
            }
        break;

        case 4:
        head=coutOfEl(head);
        break;

        case 5:
        if(!head){
            cout<<"\nYou don't have any elements! Please select 1 action!";
        } else{
            head=deleteAllStack(head);
        }
        break;

        case 6:
        cout<<"\nThe program is over!\n";
        break;
        
        default: cout<<"\nYou entered incorrect data, please try again!\n";
            break;
        }

    if(choice!=6) pauseScreen();
    } while (choice!=6);
    
    return 0;
}