/*
    Given a linked list, segregate even and odd and their order must remain same respectively ;
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
        node* ins(node* head, int d);

        node* seg_e_o(node* head);

        void disp(node* head);

};

int main(){


    int n;
    cout<<"Enter number of nodes in list: ";
    cin>>n;
    node* head=NULL;
    solution sl;

    int d;
    cout<<"Enter elements: ";
    for(int i=0;i<n;++i){
        cin>>d;
        head=sl.ins(head,d);
    }

    sl.disp(head);

    head=sl.seg_e_o(head);
    cout<<"After segregating: ";
    sl.disp(head);

    return 0;
}

node* solution::seg_e_o(node* head){

    node* evene=NULL;
    node* evens=NULL;
    node* odde=NULL;
    node* odds=NULL;
    node* temp=head;
    for(; temp!=NULL; temp=temp->next){

        if(((temp->data)&1) == 1){
            if(odds==NULL){
                odds=temp;
                odde=temp;
            }
            else{
                odde->next=temp;
                odde=odde->next;
            }
        }
        else{
            if(evens==NULL){
                evens=temp;
                evene=temp;
            }
            else{
                evene->next=temp;
                evene=evene->next;
            }

        }

    }

    if(evens==NULL || odds==NULL){
        return head;
    }
    evene->next=odds;
    odde->next=NULL;

    return evens;

}

node* solution::ins(node* head,int d){
    if(head==NULL){
        head= new node(d);
        return head;
    }
    node* temp=head;
    for(; temp->next != NULL ; temp=temp->next){}
    temp->next=new node(d);

    return head;
}

void solution::disp(node* head){
    for(; head!=NULL; head=head->next){
        cout<<head->data<<" ";
    }
    cout<<"\n";
    return ;
}