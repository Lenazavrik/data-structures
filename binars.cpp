#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
int data;
Node *left, *right;
};

Node *CreateNode()
{
Node *newNode;
newNode=new Node;
cout<<"\nIevadiet skaitli, kuru pievienot: ";
cin>>newNode->data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}

void PrintTree (Node *cur)
{
if ( ! cur ) return;
PrintTree (cur->left);
cout<<cur->data;
PrintTree (cur->right);
}

int main(){
    int choice;
    do
    {
        cout<<"1. Pievienot mezglu";
        cout<<"5. Pabeigt programmu";
        cout<<"\nIevadiet kura bus darbiba: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            CreateNode();
            break;

        case 2:
            PrintTree();
        break;

        case 6:
        cout<<"\nProgramma beidzas!";
        break;
        
        default:
        cout<<"\nIr nepareizs datu ievads!";
            break;
        }
    } while (choice!=6);
    
    return 0;
}