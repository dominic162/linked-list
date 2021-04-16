/*
    Merge 2 sorted linked list;
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
        node* merge(node* head1,node* head2);

        void display(node* head);
};

int main(){

    int n1,n2;
    cout<<"Enter number of nodes in 1st ll: ";
    cin>>n1;
    cout<<"Enter elements: ";

    node* head1=NULL;
    node* tail=NULL;
    for(int i=0;i<n1;++i){
        int d;
        cin>>d;
        if(head1==NULL){
            head1 = new node(d);
            tail = head1;
        }
        else{
            tail->next= new node(d);
            tail=tail->next;
        }
    }

    cout<<"Enter number of nodes in 2nd ll: ";
    cin>>n2;

    node* head2=NULL;
    cout<<"Enter elements: ";
    for(int i=0;i<n2;++i){
        int d;
        cin>>d;
        if(head2==NULL){
            head2= new node(d);
            tail=head2;
        }
        else{
            tail->next= new node(d);
            tail=tail->next;
        }

    }

    solution sl;

    node* head=sl.merge(head1,head2);

    sl.display(head);


    return 0;
}

void solution::display(node* head){
    for(; head != NULL; head = head->next){
        cout<<head->data<<" ";
    }
}

node* solution::merge(node* head1,node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    node* head=NULL;
    node* temp=NULL;
    while(head1!=NULL && head2!=NULL){

        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                temp = head1;
            }
            else{
                temp->next = head1;
                temp = temp->next;
            }
            head1 = head1->next;
        }
        else{
            if(head == NULL){
                head = head2;
                temp = head2;
            }
            else{
                temp->next = head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }
    }

    if(head1 != NULL){
        for(;head1!=NULL; head1=head1->next){
            temp->next=head1;
            temp = temp->next;
        }
    }
    if(head2 != NULL){
        for(; head2!=NULL; head2=head->next){
            temp->next = head2;
            temp = temp->next;
        }
    }
    return head;
}