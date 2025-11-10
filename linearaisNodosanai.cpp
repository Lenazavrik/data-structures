#include <iostream>
#include <cstdlib>
using namespace std;

struct list{
    int data;
    list *link; //adrese uz nakamo elementu
};

//create list/node
list *CreateNode ()
{
list *newNode; //izveido jaunu tipu, kurs glaba adresi
newNode = new list; //izdala atminu ar Node izmeru 8bite
cout<<"\nEnter the number to add: ";
cin>>newNode->data; //prasa ievadit skaitli/data
newNode->link=NULL; //ta ka pagaidam pedejais elements adrese ir 0
return newNode; //atgriez adresi uz tikko izveidotu mezglu
}

//print list
void PrintList (list *head)
{
list *cur;
cout<<"\nList items: ";
cur=head; //1
while (cur!=NULL){
    cout<<cur->data<<" "; //2
    cur=cur->link;
}
cout<<endl;
}

//add node beg
list *addNodeBeg(list *head){
    list *cur; //tips cur islaicigi glaba jauna tipa adresi
    cur=CreateNode(); //funkcija kura izveido jaunu tipu un atgriez ta adresi
    cur->link=head; //jaunajam mezglam tiek ierakstita iepriekeja head adrese
    head=cur; //jaunaijs cur palika par jauno head
    return head; //atgriez jauno head
}

//add node last
list *addLast(list *head){
    list *cur, *newNode; //cur lai iet pa ciklu, newNode jaunajam mezglam
    newNode=CreateNode(); //funkcija kura izveido jaunu tipu un atgriez ta adresi
    cur=head; //cur saak no 1 elementa, no head
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=newNode; //pedejam mezglam ir pievienote jauna mezgla adrese
    return head;
}

//Add data after selected node
list *addAfterSel(list *head){
    int choice;
    cout<<"\nСhoose after which element to insert the new one!";
    PrintList(head);
    cin>>choice;

    list *cur, *newNode;
    cur=head;
    while(cur!=NULL && choice!=cur->data){ // && cur->link!=NULL
        cur=cur->link; //meklejama elementa adrese
    }
    if(cur==NULL){
    cout<<"\nElement not found!\n";
    return head;
    }
    
    newNode=CreateNode();
    newNode->link=cur->link; //newNode tiek pieskirta adrese nakamajam elementam
    cur->link=newNode; //no ieprikseja elementa tiek pieskirta adrese uz newNode
    

    return head;
}

//Add data before selected node
list *addDatabefore(list *head){
    int choice;
    cout<<"\nСhoose before which element to insert the new one!";
    PrintList(head);
    cin>>choice;

    list *cur, *newNode, *prev;
    cur=head;

    if (head->data == choice) {
    newNode = CreateNode();
    newNode->link = head;
    head = newNode;
    return head;
    }

    prev = head;
    cur = head->link;   

    while(cur!=NULL && choice!=cur->data){ // && cur->link!=NULL
        prev = cur;
        cur = cur->link;
    }
    if(cur==NULL){
    cout<<"\nElement not found!\n";
    return head;
    }

    newNode=CreateNode();
    newNode->link = cur;
    prev->link = newNode;
    return head;

}

//Delete data from list at the beginning
list *deleteBeg(list *head){
    list *cur;

    if(head->link==NULL){
    delete head;
    return NULL;
    }

    cur=head; //saglabajam vecu head
    head=head->link; //nakamajs elements paliek par head
    delete cur;
    return head;
}

//Delete data from list at the end
list *deleteEnd(list *head){
    list *cur, *last=NULL;
    cur=head;

    if(head->link==NULL){
    delete head;
    return NULL;
    }

    while(cur->link!=NULL){

        last=cur; //last=priekspedejais
        cur=cur->link; //cur=pedejais elements

    }

    last->link=NULL;
    delete cur;

    return head;
}

//Delete data after selected node
list *deleteAfterSel(list *head){
    int choice;
    cout<<"\nСhoose after which element to delete the one!";
    PrintList(head);
    cin>>choice;

    list *cur, *last=NULL;
    cur=head;
    while(cur!=NULL && choice!=cur->data){ 
        last=cur;
        cur=cur->link;
    }
    if(cur==NULL){
    cout<<"\nElement not found!\n";
    return head;
    } else if(cur->link==NULL){
        cout<<"\nThe selected item is the last one, the action could not be performed!\n";
        return head;
    }

    last=cur->link;
    cur->link=last->link;
    delete last;
    return head;

}

//Delete data before selected node
list *deleteBeforeSel(list *head){
    int choice;
    cout<<"\nСhoose before which element to delete the one!";
    PrintList(head);
    cin>>choice;

    list *cur, *prev=NULL, *prev1=NULL;
    prev=head;
    cur=head->link;

    while(cur!=NULL && cur->data!=choice){ 
    prev1=prev;
    prev=cur;
    cur=cur->link;
    }

    if(choice==head->data){
        cout<<"\nThere is nothing before the first element, it cannot be deleted\n";
        return head;
    }

    if(cur==NULL){
    cout<<"\nElement not found!\n";
    } else if(cur==head->link){
        head=cur;
        delete prev;
    } else {
        prev1->link=cur;
        delete prev;
    }

    return head;
}

//Determining the number of list elements
list *numberOfElements(list *head){
    int i=0;
    list *cur;
    cur=head;
    if(!head){
        cout<<"\nThere are 0 elements in the list.";
        return head;
    }
    while(cur!=NULL){
        cur=cur->link;
        i++;
    }

    cout<<"\nThere are "<<i<<" elements in the list.";
    return head;
}

//Deleting the entire list
list *deleteAllList(list *head){
    list *cur, *next;
    if(!head){
    cout<<"\nThere are 0 elements in the list.";
    return head;
    }
    cur=head;
    while(cur!=NULL){
        next=cur;
        cur=cur->link;
        delete next;
    }
    return NULL;
}

int main(){

    list *head=NULL; //adrese tipa list, kura saucas head
    int choice;
    do{
        cout<<"\nSelect action: ";
        cout<<"\n1. Add head"; //.
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

        cout<<"\n\nSelect action: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
        if(!head){
            head=CreateNode();
        } else {
            cout<<"\nHead already exists: ";
            PrintList(head);
            cout<<endl;
        }
        break;

        case 2:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
        head=addNodeBeg(head);
        PrintList(head);
        }
        break;

        case 3: 
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else{
            addLast(head);
            PrintList(head);
        }
        break;

        case 4:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
        addAfterSel(head);
        PrintList(head);
        }
        break;

        case 5: 
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
        head=addDatabefore(head);
        PrintList(head);
        }
        break;

        case 6:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
        head=deleteBeg(head);
        PrintList(head);
        }
        break;

        case 7:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
        head=deleteEnd(head);
        PrintList(head);
        }
        break;

        case 8:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
        head=deleteAfterSel(head);
        PrintList(head);
        }
        break;

        case 9:
        if(!head){
            cout<<"\n\nYou have no head! Please select 1 action!\n";
        } else {
        head=deleteBeforeSel(head);
        PrintList(head);
        }
        break;

        case 10:
        PrintList(head);
        break;

        case 11:
        head=numberOfElements(head);
        PrintList(head);
        break;

        case 12:
        head=deleteAllList(head);
        PrintList(head);
        break;
        
        case 13:
        cout<<"\nThe program is over!\n";
        break;
        
        default:
        cout<<"\nYou entered incorrect data, please try again!\n";
            break;
        }
    }
    while(choice!=13);
    return 0;
}