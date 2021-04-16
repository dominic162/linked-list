/*
    Given a list, find if it has loop;
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int d):data(d),next(NULL){
        }
};

class solution{

    public:
        bool has_loop(node* head);

};

int main(){

    solution sl;
    
    node* head=new node(10);
    
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=head;


    if(sl.has_loop(head)){
        cout<<"List has loop";
    }
    else{
        cout<<"List doesn't has loop";
    }

    return 0;
}

bool solution::has_loop(node* head){
    
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast){
            return true;
        }
    }

    return false;

}