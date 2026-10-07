#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

struct Node
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


//List output
Node *listOutput(Node *head){
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

//Add data for list at the beginning
Node *addDataBeg(Node *head){
    Node *cur, *newNode;
    cur=head;
    newNode=createNode();
    newNode->link=cur;
    head=newNode;
    return head;
}

//Add data for list at the end
Node *addDataEnd(Node *head){
    Node *cur, *newNode;
    cur=head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    newNode=createNode();
    cur->link=newNode;
    return head;
}

//Add data after selected node
Node *addDataAfter(Node *head){
    Node *cur, *newNode;
    int choice;
    listOutput(head);
    cout<<"\nСhoose after which element to insert the new one: ";
    choice=safeInputInt();
    cur=head;
    while (cur!=NULL && choice!=cur->data)
    {
        cur=cur->link;
    }
    if(cur==NULL){
        cout<<"\nElement not found, try again!\n";
        return head;
    }
    if(cur->link==NULL){
        newNode=createNode();
        cur->link=newNode;
        return head;
    }
    newNode=createNode();
    newNode->link=cur->link;
    cur->link=newNode;
    return head;
    
}

//Add data before selected node
Node *addDataBefore(Node *head){
    int choice;
    listOutput(head);
    cout<<"\nСhoose before which element to insert the new one: ";
    choice=safeInputInt();
    Node *cur, *prev=NULL, *newNode;
    cur=head;
    while (cur!=NULL && cur->data!=choice)
    {
        prev=cur;
        cur=cur->link;
    }
    if(cur==NULL){
        cout<<"\nElement not found, try again!\n";
        return head;
    }
    if(cur==head){
        newNode=createNode();
        newNode->link=cur;
        head=newNode;
        return head;
    }
    newNode=createNode();
    prev->link=newNode;
    newNode->link=cur;
    return head;
}

//Delete data from list at the beginning
Node *deleteFirst(Node *head){
    Node *cur;
    cur=head;
    head=cur->link;
    delete cur;
    return head;
}

//Delete data from list at the end
Node *deleteLast(Node *head){
    Node *cur, *prev;
    listOutput(head);
    cur=head;
    while (cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    if(head->link==NULL){
        delete head;
        return NULL;
    }
    prev->link=NULL;
    delete cur;
    return head;
    
}

//Delete data after selected node
Node *deleteAfterSel(Node *head){
    Node *cur, *next, *remove;
    int choice;
    listOutput(head);
    cout<<"\nСhoose after which element to delete: ";
    choice=safeInputInt();

    cur=head;
    while (cur!=NULL && cur->data!=choice)
    {
        cur=cur->link;
    }

    if(cur==NULL){
        cout<<"\nElement not found, try again!\n";
        return head;
    }

    if(cur->link==NULL){
        cout<<"\nThere is nothing to delete after the last element, try again!\n";
        return head;
    }
    
    remove=cur->link;
    next=remove->link;
    cur->link=next;
    delete remove;
    return head;
}

//Delete data before selected node
Node *deleteBeforeSel(Node *head){
    Node *cur, *remove, *prev;
    int choice;
    listOutput(head);
    cout<<"\nСhoose before which element to delete: ";
    choice=safeInputInt();

    if(choice==head->data){
        cout<<"\nThere is nothing to delete before the first element, try again!\n";
        return head;
    }

    if(head->link==NULL){
        cout<<"\nElement not found, try again!\n";
        return head;
    }

    prev=head;
    remove=prev->link;
    cur=remove->link;

    if(choice==remove->data){
        head=remove;
        delete prev;
        return head;
    }

    while (cur!=NULL && cur->data!=choice)
    {
        prev=remove;
        remove=cur;
        cur=cur->link;
    }
    if(cur==NULL){
        cout<<"\nElement not found, try again!\n";
        return head;
    }
    
    prev->link=cur;
    delete remove;
    return head;
    
}

//Determining the number of list elements
Node *elementCount(Node *head){
    Node *cur;
    int count=0;
    cur=head;
    while (cur!=NULL)
    {
        cur=cur->link;
        count++;
    }
    cout<<"\nIt is "<<count<<" elements in the list.\n";
    return head;
}

//Deleting the entire list
Node *deleteAllList(Node *head){
    Node *cur, *prev;
    cur=head;
    while (cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
        delete prev;
    }
    head=NULL;
    return head;
}

int main(){
    Node *head=NULL; //adrese tipa Node, kura saucas head
    int choice;
    
    do
    {
        clearScreen();
        cout<<"\nAutors: Vladlena Klimova\n";
        cout<<"\nSelect action: ";
        cout<<"\n1. Add head";//
        cout<<"\n2. Add data for list at the beginning";//
        cout<<"\n3. Add data for list at the end";//
        cout<<"\n4. Add data after selected node";//
        cout<<"\n5. Add data before selected node";//
        cout<<"\n6. Delete data from list at the beginning";//
        cout<<"\n7. Delete data from list at the end";//
        cout<<"\n8. Delete data after selected node";//
        cout<<"\n9. Delete data before selected node";//
        cout<<"\n10. List output";//
        cout<<"\n11. Determining the number of list elements";//
        cout<<"\n12. Deleting the entire list";
        cout<<"\n13. Finish the program";//

        cout << "\nSelect action: ";
        choice=safeInputInt();

        switch (choice)
        {
        case 1:
            if(!head){
                head=createNode();
            } else{
                cout<<"\nHead already exists: "<<head->data;
                cout<<endl;
            }
            break;
        
        case 2:
            if(!head){
                cout<<"\n\nYou have no head! Please select 1 action!\n";
            } else{
                head=addDataBeg(head);
                head=listOutput(head);
            }
        break;

        case 3:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=addDataEnd(head);
            head=listOutput(head);
        }
        break;

        case 4:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=addDataAfter(head);
            head=listOutput(head);
        }
        break;

        case 5:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=addDataBefore(head);
            head=listOutput(head);
        }
        break;

        case 6:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=deleteFirst(head);
            head=listOutput(head);
        }
        break;

        case 7:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=deleteLast(head);
            head=listOutput(head);
        }
        break;

        case 8:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=deleteAfterSel(head);
            head=listOutput(head);
        }
        break;

        case 9:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=deleteBeforeSel(head);
            head=listOutput(head);
        }
        break;

        case 10:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
            head=listOutput(head);
        }
        break;

        case 11:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=elementCount(head);
        }
        break;

        case 12:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            head=deleteAllList(head);
        }
        break;
        
        case 13:
        cout<<"\nThe program is over!\n";
        break;

        default: 
        cout<<"\nYou entered incorrect data, please try again!\n";
            break;
        }
        if(choice!=13) pauseScreen();
    } while (choice!=13);
    
    return 0;
}