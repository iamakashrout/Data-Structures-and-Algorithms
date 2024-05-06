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

Node* reverse(Node* head, Node* tail){ // reverse current group, tail represents remaining part of linked list
    Node* prev=tail;
    while(head!=tail){
        Node* temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}

Node* kReverse(Node* head, int k){
    Node* temp=head;
    for(int i=0; i<k; i++){ // check k group
        if(temp==NULL){
            return head;
        }
        temp=temp->next;
    }
    Node* ans=reverse(head, temp); // reverse 1st k group
    head->next=kReverse(temp, k); // recursively reverse all next k groups
    return ans;
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
    int k;
    cin>>k;
    head=kReverse(head, k);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}