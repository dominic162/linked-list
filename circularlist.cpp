//traversal of circular linked list
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int d,node* ref=NULL){
            this->data=d;
            this->next=ref;
        }
};

class circularlist{ 
    //class for operations on circular list
    public:
        node* head;

        void display(){
            node* p=head;
            do
            {
                cout<<p->data<<" ";
                p=p->next;
            } while (p!=head);
            
            cout<<"\n";
        }

        //insertion 

        void insertend(int d){
            insertbegin(d);
            head=head->next;
        }


        //insertion at begining of a linked list
        void insertbegin(int d){
            
            if(head==NULL){
                head=new node(d);
                head->next=head;
            }
            else{
                node* temp=new node(head->data,head->next);
                head->data=d;
                head->next=temp;
            }

        }


        circularlist(){
            this->head=NULL;
        }
};

int main(){

    circularlist cl;
    int n;
    cout<<"enter no of elements: ";
    cin>>n;

    for(int t=0;t<n;t++){
        int d;
        cin>>d;
        cl.insertend(d);
    }
    
    int fr;
    cout<<"enter element to be inserted at front: ";
    cin>>fr;
    cl.insertbegin(fr);
    
    cl.display();
    
    cout<<"enter element to be inserted at end: ";
    cin>>fr;
    cl.insertend(fr);

    cl.display();

    return 0;
}