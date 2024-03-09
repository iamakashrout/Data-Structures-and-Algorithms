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

bool hasCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    // slow and fast will intersect if there is cycle, else fast will reach to end of linked list
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

Node* cycleStart(Node* head){
    Node* slow=head;
    Node* fast=head;
    bool isCycle=false;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            isCycle=true;
            break;
        }
    }
    if(!isCycle){
        return NULL;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
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
    temp->next=head; // add cycle for testing
    if(hasCycle(head)){
        cout<<"Yes"<<endl;
        Node* s=cycleStart(head);
        cout<<s->data<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}