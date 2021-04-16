#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
int main(){
	node* head=NULL;
	node* tail=NULL;
	node* s=NULL;
	node* h=NULL;
	int n,i=0;
	cout<<"enter the number of elements in linked list"<<endl;
	cin>>n;
	cout<<endl<<"enter elements of linked list"<<endl;
	for(i=0;i<n;i++){
		if(head==NULL){
			head=new node();
			cin>>head->data;
			tail=head;
			s=head;
		}
		else{
			tail->next=new node();
			tail=tail->next;
			cin>>tail->data;
		}
	}
	head=s;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	//search an element in linked list
	cout<<endl<<"enter the element you want to search"<<endl;
	int search,help=0;
	cin>>search;
	head=s;
	while(head!=NULL){
		if(head->data==search){
			help=1;
			cout<<"PRESENT"<<endl;
			break;
		}
		else
			head=head->next;
	}
	if(help==0)
	cout<<endl<<"NOT PRESENT"<<endl;
	//insert an element in linked list
	int insert,p;
	head=s;
	cout<<endl<<"enter the position you at which you want to add the element"<<endl;
	cin>>p;
	cout<<endl<<"enter the element you want to insert"<<endl;
	cin>>insert;
	if(p==0){
		head=new node();
		h=head;
		head->data=insert;
		head->next=s;
		head=h;
	}
	else{
		for(i=0;i<p-1;i++){
			head=head->next;
		}
		h=head->next;
		head->next=new node();
		head=head->next;
		head->data=insert;
		head->next=h;
		head=s;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	//delete a node
	int delt;
	node* headp=NULL;
	head=s;
	cout<<endl<<"enter the element you want to delete"<<endl;
	cin>>delt;
	headp=s;
	if(head->data==delt){
		headp=head->next;
		while(headp!=NULL){
			cout<<headp->data<<" ";
			headp=headp->next;
		}
	}
	else{
		headp=head;
		for(i=0;i<n;i++){
			if(head->data==delt){
				headp->next=head->next;
				break;
			}
			else{
				headp=head;
				head=head->next;
			}
		}
		headp=s;
		while(headp!=NULL){
			cout<<headp->data<<" ";
			headp=headp->next;
		}
	}
	return 0;
}
