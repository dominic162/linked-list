#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};

Node* insertnode(Node* head,int d){

    if(head==NULL){
        head=new Node(d);
    }
    else{
        Node* temp=head;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=new Node(d);
        head=temp;
    }
    return head;
}

void displayllist(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* insertelem(Node* head,int d){

    Node* temp=new Node(d);
    Node* href=head;
    if(head==NULL || head->data>d){
        
        temp->next=head;
        
        return temp;
    }

    Node *prev=NULL;
    while(head!=NULL && head->data<d){
        prev=head;
        head=head->next;
    }

    temp->next=prev->next;
    prev->next=temp;

    return href;

}

int main(){

    int n,d;
    cout<<"Enter number of nodes in list: ";
    cin>>n;
    Node* head=NULL;
    cout<<"Enter elements: ";
    for(int t=0;t<n;t++){
        cin>>d;
        head=insertnode(head,d);
    }

    displayllist(head);
    
    int elem;

    cout<<"\nEnter element to be inserted: ";
    cin>>elem;

    head=insertelem(head,elem);

    displayllist(head);


    return 0;
}