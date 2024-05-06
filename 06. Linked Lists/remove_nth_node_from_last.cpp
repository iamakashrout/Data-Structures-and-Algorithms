#include<bits/stdc++.h>
using namespace std;

class Node{ // LINKED LIST CLASS
public:
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* solve(Node* head, int n){
    Node* slow=head;
    Node* fast=head; // maintains gap of n nodes from slow
    for(int i=0; i<n; i++){
        fast=fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while(fast->next!=NULL){ // send fast to the end, this way slow points to the (n+1)th node from last
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next; // remove nth node from last
    return head;
}

int main(){
    int n;
    cin>>n;
    int first;
    cin>>first;
    Node* head=new Node(first); // create first node
    Node* temp=head;
    for(int i=0; i<n-1; i++){
        int x;
        cin>>x;
        Node* curr=new Node(x); // rest of the nodes
        temp->next=curr;
        temp=temp->next;
    }
    int num;
    cin>>num;
    head=solve(head, num);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}