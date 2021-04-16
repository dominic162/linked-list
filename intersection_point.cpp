/*
    Given 2 linked list which intersects at a point, find its intersection point;
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
        int intersect(node* head1,node* head2);
};

int main(){
    node* head1=new node(10);
    head1->next=new node(20);
    head1->next->next=new node(30);
    
    node* head2=new node(5);
    head2->next=new node(6);
    head2->next->next=head1->next;

    solution sl;
    if(sl.intersect(head1,head2) == -1){
        cout<<"No intersection ";
    }
    else{
        cout<<"Intersecting value "<<sl.intersect(head1,head2);
    }

    return 0;
}

int solution::intersect(node* head1, node* head2){
    int len1=0,len2=0;
    node* temp=head1;
    for(;temp!=NULL; temp=temp->next){
        len1++;
    }
    temp=head2;
    for(;temp!=NULL; temp=temp->next){
        len2++;
    }
    int diff=abs(len1-len2);
    if(len1>len2){
        for(int i=0;i<diff;++i){
            head1=head1->next;
        }
    }
    else{
        for(int i=0;i<diff;++i){
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        if(head1==head2){
            return head1->data;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}