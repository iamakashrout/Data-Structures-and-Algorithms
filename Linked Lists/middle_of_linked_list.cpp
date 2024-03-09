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

Node* findMid(Node* head){
    Node* slow=head;
    Node* fast=head; // moves at 2x speed of slow, when fast reaches end, slow reaches mid
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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
    Node* middle=findMid(head);
    cout<<middle->data<<endl;
    return 0;
}