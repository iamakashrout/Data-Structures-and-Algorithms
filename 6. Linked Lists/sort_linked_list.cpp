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

Node* mergeLL(Node* head1, Node* head2){ // merging two sorted linked lists
    Node* res=new Node(0);
    Node* curr=res;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            curr->next=head1;
            head1=head1->next;
        }
        else{
            curr->next=head2;
            head2=head2->next;
        }
        curr=curr->next;
    }
    if(head1!=NULL){
        curr->next=head1;
    }
    if(head2!=NULL){
        curr->next=head2;
    }
    return res->next;
}

Node* sortLL(Node* head){ // using merge sort technique
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=NULL;
    // divide list into two parts
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        temp=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
    temp->next=NULL;
    // sort each half individually
    Node* left=sortLL(head);
    Node* right=sortLL(slow);
    return mergeLL(left, right); // merge sorted halves
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
    head=sortLL(head);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}