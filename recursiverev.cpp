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

node* reverselist(node* head,node* prev){

    if(head==NULL){
        return prev;
    }

    node* temp=head->next;

    head->next=prev;

    return reverselist(temp,head);

}

int main(){

    int n;
    cout<<"enter no of elements: ";
    cin>>n;
    node* head=NULL;
    for(int t=0;t<n;t++){
        int d;
        cin>>d;
        head=insertnode(head,d);
    }

    displaylist(head);

    head=reverselist(head,NULL);

    displaylist(head);

    return 0;
}