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
    if(head==NULL){
        head=new node(d);
        return head;
    }
    node* temp=head; 
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=new node(d);
    return temp;
}

void displaylist(node* head){
    cout<<"\n";
    
    for(;head!=NULL;head=head->next){
        cout<<head->data<<" ";
    }

    cout<<"\n";
}

void removedupli(node* head){

    if(head==NULL){
        return ;
    }

    int prev=head->data;
    node *curr=head;
    node* temp=head->next;

    for(;temp!=NULL;){
        if(temp->data!=prev){
            curr->next=temp;
            curr=temp;
            prev=temp->data;
            temp=temp->next;
        }
        else{
            node *ex=temp;
            temp=temp->next;
            delete ex;
        }
    }

    curr->next=NULL;

    return ;


}

int main(){

    int n;
    node* head=NULL;

    cout<<"enter number of elements: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int t=0;t<n;t++){
        int d;
        cin>>d;
        head=insertnode(head,d);
    }

    displaylist(head);
    
    removedupli(head);

    displaylist(head);

    return 0;
}