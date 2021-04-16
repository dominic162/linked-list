/*
    Given a linked list , pairwise swap it;
*/


#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int d):data(d),next(NULL){}
};

class solution{
    public:
        node* pair_swap(node* head);

        node* ins(node* head,node* tail,int d);

        void display(node* head);
};

int main(){

    int n,d;
    cout<<"Enter number of nodes in linked list: ";
    cin>>n;
    
    solution sl;
    node* head=NULL;
    node* tail=NULL;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;++i){
        cin>>d;
        tail=sl.ins(head,tail,d);
        if(head==NULL){
            head=tail;
        }
    }   

    sl.display(head);

    head=sl.pair_swap(head);

    sl.display(head);

    return 0;
}

inline void solution::display(node* head){
    for(;head!=NULL;head=head->next){
        cout<<head->data<<" ";
    }
    cout<<endl;
    return ;
}

node* solution::ins(node* head,node* tail,int d){ 
    if(head==NULL){
        head=new node(d);
        return head;
    }

    tail->next = new node(d);
    tail=tail->next;
    return tail;
}

node* solution::pair_swap(node* head){

    if(head==NULL|| head->next==NULL){
        return head;
    }

    node* chead=NULL;
    node* ctail=NULL;
    node* temp=head;
    node* tail=NULL;
    while(temp!=NULL && temp->next!=NULL){
        chead=temp->next;
        ctail=temp;
        ctail->next=chead->next;
        chead->next=ctail;
        if(tail == NULL){
            head=chead;
        }
        else{
            tail->next=chead;
        }
        tail=ctail;
        temp=ctail->next;
    }

    return head;

}
