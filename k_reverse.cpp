/*
    Given a linked list, reverse it in groups;
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int d){
            this->data = d;
            this->next = NULL;
        }
};

class solution{

    public:
        void disp_llist(node* head);

        node* ins_node(node* head , int d);

        node* rev_grp(node* head, int k);

};

int main(){

    int n;
    cout<<"Enter number of nodes in linked list: ";
    cin>>n;
    int k;
    cout<<"Enter elements of linked list: ";
    node* head=NULL;

    solution sl;


    for(int i=0 ; i<n ; ++i){
        cin>>k;
        head = sl.ins_node(head,k);
    }

    sl.disp_llist(head);

    cout<<"Enter value of k: ";
    cin>>k;

    head = sl.rev_grp(head,k);

    sl.disp_llist(head);



    return 0;
}

void solution::disp_llist(node* head){
    for(; head!=NULL; head=head->next){
        cout<<head->data<<" ";
    }

    return ;
}

node* solution::ins_node(node* head,int d){

    if( head == NULL ){
        head = new node(d);
        return head;
    }

    node* temp=head;
    for( ; head->next != NULL; head = head->next ){
    }

    head->next = new node(d);
    return temp;

}

node* solution::rev_grp(node* head, int k){

    if(head==NULL || k == 0){
        return head;
    }

    node* tail=head;
    node* pre=NULL;
    node* temp;
    int count=0;

    while(head!=NULL && count<k){
        temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
        ++count;
    }

    tail->next = rev_grp(head,k);

    return pre;

}