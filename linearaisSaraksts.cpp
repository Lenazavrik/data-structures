#include <iostream>
#include <cstdlib>
using namespace std;
//nodot 16.10.2025

struct Node
{
    int data;
    Node *link;
};

Node *CreateNode ()
{
Node *newNode; //1
newNode = new Node; //izdala atminu ar Node izmeru 8bite
cout<<"\nIevadiet skaitli, kuru pievienot: ";
cin>>newNode->data; //3
newNode->link=NULL; //4
return newNode; //5
}

void PrintList (Node *head)
{
Node *cur;
cout<<"Saraksta elementi:\n";
cur=head; //1
while (cur!=NULL)
{cout<<cur->data<<" "; //2
cur=cur->link;
}
}

/*Node *pievienosana(Node *head){
        Node *cur;
        cur=CreateNode();
        cur->link=head;
        head=cur;
        return head;
}*/

Node *addLast(Node *head){
    Node *cur, *newNode;
    newNode=CreateNode();
    cur=head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=newNode;
}

//dzest pedejo
Node* deletelast(Node *head){
    Node *cur, *prev=NULL;
    cur=head;
    while(cur->link!=NULL){
        prev=cur;
        cur=cur->link;
    }
    prev->link=NULL;
    delete cur;
    return head;
}

//Pievenot beigaas
Node *addlast(Node *head){
    Node *cur;
    cur=head;
    while (cur!=NULL)
    {
        
    }
    
}

int main(){
    Node *head=NULL, *mezgls2, *mezgls3, *cur; //head=mezgls1
    //head=CreateNode();
   // mezgls2=CreateNode();
   // mezgls3=CreateNode();
   // head->link=mezgls2;
   //mezgls2->link=mezgls3;
    //PrintList(head);
    int izvele;

    do{
        //system("cls");
        cout<<"\n1. Izveidot Head";
        cout<<"\n2. Izvadit vertibu no Head";
        cout<<"\n3. Pievienot Node sakumaa";
        cout<<"\n4. Pievenot beigaas";
        cout<<"\n5. Dzest pedejo";
        cout<<"\n6. Ievadiet lai pabeigtu  programmu";
        cout<<"\nIevadiet darbibu: ";
        
        cin>>izvele;
        switch (izvele)
        {
        case 1:
        if(!head){
            head=CreateNode();
        } else {
            cout<<"\nHead jau ir: ";
            PrintList(head);
        }
         
        break;
        
        case 2:
        PrintList(head);
        //system("pause>nul");
        break;

        case 3: 
        //head=pievienosana(head);
        addLast(head);
        break;

        case 5:
            deletelast(head);
        break;

        case 6:
        cout<<"\nProgramma pabeigta!";
        break;

        default:
        cout<<"\nNepareiza izvele";
            break;
        }
    }
    while(izvele!=4);
    
    /*
    cout<<"\nhead->data= "<<head->data<<endl;
    cout<<"\nhead->link= "<<head->link<<endl;
    cout<<"\nadrese head= "<<head<<endl;

    //head->link= 0x130704080 == adrese mezgls2= 0x130704080
    cout<<"\nMezgls2->data= "<<mezgls2->data<<endl;
    cout<<"\nMezgls2->link= "<<mezgls2->link<<endl;
    cout<<"\nadrese mezgls2= "<<mezgls2<<endl;*/
    cout<<endl;
    return 0;
}