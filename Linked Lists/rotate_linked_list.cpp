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

Node* rotateLL(Node* head, int k){
    if(head==NULL || head->next==NULL || k==0){
        return head;
    }
    Node* temp=head;
    int length=1;
    while(temp->next!=NULL){
        temp=temp->next;
        length++;
    }
    k=k%length;
    temp->next=head;
    int pos=length-k; // elements to shift right
    while(pos--){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;
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
    int k;
    cin>>k;
    head=rotateLL(head, k);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}