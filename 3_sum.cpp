/*
    Given a sorted doubly linked list and a target , find triplets with sum equal to target; 
*/

#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

class node{
    public:
        int data;
        node *next , *prev;

        node(int d):data(d),next(NULL),prev(NULL){
        }
};

class solution{
    public:

        void add_node(node* &head , node* &tail , int x); 

        vector< tuple < int , int , int > > ans(node* head , node* tail , int target);
};

int main(){

    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;

    node* head = NULL;
    node* tail = NULL;

    cout<<"Enter value of nodes: ";
    int x;
    solution sl;

    for(int i = 0 ; i < n ; ++i){
        cin>>x;
        sl.add_node(head , tail , x);
    }

    cout<<"Enter sum: ";
    cin>>x;

    vector < tuple < int , int , int > > ansv = sl.ans( head , tail , x );

    cout<<"Pairs having sum equal to "<<x<<" are:\n";
    for(int i = 0 ; i < ansv.size() ; ++i){
        cout<< get<0>(ansv[i]) <<" "<< get<1>(ansv[i]) <<" "<< get<2>(ansv[i]) <<endl;
    }
    

    return 0;
}

void solution::add_node(node* &head , node* &tail , int x){

    if(tail == NULL){
        head = new node(x);
        tail = head;
    }
    else{
        tail->next = new node(x);
        tail->next->prev = tail;
        tail = tail->next;
    }

    return ; 

}

vector < tuple < int , int , int > > solution::ans(node* head , node* tail , int target){
    node* ddl = head;

    vector < tuple < int , int , int > > ans;
    for( ; ddl->next->next != NULL ; ddl = ddl->next){
        tuple < int , int , int > t1;
        node* temp1 = ddl->next;
        node* temp2 = tail;
        int rsum = target - ddl->data;
        while(temp1 != temp2 && temp1->prev != temp2){

            int csum = temp1->data + temp2->data;

            if(csum > rsum){
                temp2 = temp2->prev;
            }
            else{
                if(csum < rsum){
                    temp1 = temp1->next;
                }
                else{
                    t1 = make_tuple(ddl->data , temp1->data , temp2->data);
                    ans.push_back(t1);
                    temp1 = temp1->next;
                    temp2 = temp2->prev;
                }
            }

        }

    }

    return ans;

}