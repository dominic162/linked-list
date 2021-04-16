/*
    Given a linked list with loop, remove the loop;
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

        void rem_loop(node* head);
};

int main(){
    solution sl;
    node* head=new node(10);
    node* tail=head;
    tail->next= new node(20);
    tail=tail->next;
    tail->next=new node(30);
    tail=tail->next;
    tail->next=head;
    node* temp=head;

    sl.rem_loop(head);


    for(;temp!=NULL; temp = temp->next){
        cout<<temp->data<<" ";
    }

    return 0;
}

void solution::rem_loop(node* head){

    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL ){ //floyd algo for cycle detection;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow != fast){   //if loop doesn't exist then return
        return ;
    }

    slow = head;    //point slow to head
    
    if(slow == fast){   //checks if the loop ends at start
        while(fast->next != slow){
            fast = fast->next;
        }
    }
    else{

        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return ;
}
