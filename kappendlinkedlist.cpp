
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
int main(){
	int n,i=0,k;
	cout<<"enter the number of elements you want to enter:-";
	cin>>n;
	cout<<endl<<"enter the elements of linked list:-";
	node* head=new node();
	cin>>head->data;
	node* s=new node();
	s=head;
	for(i=1;i<n;i++){
		head->next=new node();
		head=head->next;
		cin>>head->data;
	}
	node* end=new node();
	end=head;
	head=s;
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
	cout<<"enter the value of k";
	cin>>k;
	k=k%n;
	head=s;
	if(k!=n){
	for(i=0;i<n-k-1;i++){
		head=head->next;
	    end->next=s;
	}
	node* help=new node();
	help=head->next;
	head->next=NULL;
	s=help;
    }
	head=s;
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL";
	return(0);
}
