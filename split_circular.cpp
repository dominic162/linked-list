/*
    Give a circular linked list , split it into 2 halves;
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d):data(d),next(NULL){
        }
};

class Solution{

    public:

        void split( Node* head , Node* &head1 , Node* &head2 );

        void add_node( Node* &head , Node* &tail , int x);

        void disp(Node* head);
};


int main(){

    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;
    
    Node *head = NULL , *tail = NULL;

    cout<<"Enter elements: ";
    Solution sl;

    for(int i = 0 ; i < n ; ++i){
        int x;
        cin>>x;
        sl.add_node(head, tail , x);
    }

    Node *head1 = NULL , *head2 = NULL;

    sl.split(head , head1 , head2);

    sl.disp(head1);
    sl.disp(head2);
    
    return 0;
}

void Solution::add_node(Node* &head , Node* &tail , int x){
    if(tail == NULL){
        head = new Node(x);
        head->next = head;
        tail = head;
    }
    else{
        tail->next = new Node(x);
        tail = tail->next;
        tail->next = head;
    }
    return ;
}

void Solution::split(Node* head , Node* &head1 , Node* &head2){

    Node *tort = head , *hare = head;

    while( hare->next != head && hare->next->next != head ){
        tort = tort->next;
        hare = hare->next->next;

    }

    if(hare->next->next == head){
        hare = hare->next;
    }


    if(head->next != head){
        head2 = tort->next;
    }
    hare->next = tort->next;

    head1 = head;
    tort->next = head;

    return ;

}

void Solution::disp(Node* head){

    cout<<"\nElements are: ";
    Node* tail = head;

    if(head == NULL){
        return ;
    }

    cout<<tail->data<<" ";
    tail = tail->next;

    for( ; tail != head ; tail = tail->next){
        cout<<tail->data<<" ";
    }
    
    return;

}