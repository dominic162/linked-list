#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;
        node(int d){
            this->data=d;
            this->prev=NULL;
            this->next=NULL;
        }
};

class doublylist{
    public:
        node* head=NULL;
        node* tail=NULL;

        //insert at end of list
        void insert(int d){
            if(tail==NULL){
                head=new node(d);
                tail=head;
            }
            else{
                node* temp=new node(d);
                tail->next=temp;
                temp->prev=tail;
                tail=tail->next;
            }
        }
        
        //display elements of list
        void display(){
            node* temp=head;

            cout<<"\nElements of list are: ";
            for(;temp!=NULL;temp=temp->next){
                cout<<temp->data<<" ";
            }
            cout<<"\n";
        
        }

        //reverse the list

        void reversel(){
            node* temp=head;
            node* help;
            for(;head!=NULL;head=head->prev){
                help=head->next;
                head->next=head->prev;
                head->prev=help;
            }
            this->head=this->tail;
            this->tail=temp;
        }

        //delete head of list

        void deleteh(){
            if(head==NULL)
                return;

            if(head==tail){
                node* temp=head;
                head=NULL;
                tail=NULL;
                delete temp;
                return ;
            }

            node* temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;

        }

        //delete last element of list

        void deletet(){

            if(tail==NULL)
                return ;
            
            if(head==tail){
                this->deleteh();
            }

            node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete temp;

        }

};

int main(){

    doublylist dbl;
    int n;
    cout<<"enter no of elements in list: ";
    cin>>n;

    cout<<"enter elements: ";
    for(int t=0;t<n;t++){
        int d;
        cin>>d;
        dbl.insert(d);
    }

    dbl.display();

    dbl.reversel();
    dbl.display();

    dbl.deleteh();
    dbl.display();

    dbl.deletet();
    dbl.display();
    
    return 0;
}