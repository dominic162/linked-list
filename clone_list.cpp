/*
    Given a linked list with next and random pointer, clone it;
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* random;
        node(int d):data(d),next(NULL),random(NULL){}  
};

class solution{
    public:
        node* clone(node* head);

        void display(node* head);
};

int main(){
    node* head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->random=head->next->next;
    solution sl;
    node* clone = sl.clone(head);
    sl.display(clone);
    return 0;
}

void solution::display(node* head){
    cout<<head->random->data<<endl;
    for(; head!=NULL ; head=head->next){
        cout<<head->data<<" ";
    }
    return ;
}

node* solution::clone(node* head){

    if(head==NULL){
        return NULL;
    }

    node* clone;
    node* temp=head;

    for(; temp!=NULL; temp=temp->next->next){
        clone = new node(temp->data);
        clone->next=temp->next;
        temp->next=clone;
    }

    for(temp=head; temp!=NULL; temp=temp->next->next){
        if(temp->random != NULL){
            temp->next->random = temp->random->next;
        }
    }
    temp=head;
    clone = temp->next;
    node* ans=clone;
    for(; clone->next !=NULL; ){
        temp->next=temp->next->next;
        clone->next=clone->next->next;
        temp=temp->next;
        clone=clone->next;
    }

    temp->next=NULL;

    return ans;

}