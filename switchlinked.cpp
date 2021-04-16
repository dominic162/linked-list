#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int d){
            this->data=d;
            this->next=NULL;
        }
};

node* insertnode(node* head,int d){

    node* temp=new node(d);
    temp->next=head;

    return temp;
}

void traverse(node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return ;
    
}

bool search(node* temp,int d){

    while(temp!=NULL){
        if(temp->data==d){
            return true;
        }
        temp=temp->next;
    }

    return false;

}

int main(){

    node* head=NULL;
    int d;
    char ch;
    do{

        cout<<"\n Enter 1 for insertion at beginning \n 2 for traversing\n 3 for searching\n 4 for exit";
        cin>>ch;

        switch(ch){
            case '1':
                cout<<"Enter element to be inserted: ";
                cin>>d;
                head=insertnode(head,d);
                break;
            
            case '2':
                traverse(head);
                break;
            
            case '3':
                cout<<"Enter element to be searched: ";
                cin>>d;
                if(search(head,d)){
                    cout<<"Element found";
                }
                else{
                    cout<<"Element not found";
                }
                break;
        }

    }while(ch!='4');

    return 0;
}