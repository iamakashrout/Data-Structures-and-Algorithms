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

// numbers are represented in reverse order
Node* add(Node* head1, Node* head2){
    Node* ans=new Node(0);
    Node* temp=ans;
    int carry=0;
    while(head1!=NULL || head2!=NULL || carry>0){
        int curr=0;
        if(head1){
            curr+=head1->data;
            head1=head1->next;
        }
        if(head2){
            curr+=head2->data;
            head2=head2->next;
        }
        if(carry>0){
            curr+=carry;
        }
        carry=curr/10;
        curr=curr%10;
        Node* x=new Node(curr);
        temp->next=x;
        temp=temp->next;
    }
    return ans->next;
}

int main(){
    int n1;
    cin>>n1;
    int first1;
    cin>>first1;
    Node* head1=new Node(first1); // create first node
    Node* temp1=head1;
    for(int i=0; i<n1-1; i++){
        int x;
        cin>>x;
        Node* curr=new Node(x); // rest of the nodes
        temp1->next=curr;
        temp1=temp1->next;
    }
    int n2;
    cin>>n2;
    int first2;
    cin>>first2;
    Node* head2=new Node(first2); // create first node
    Node* temp2=head2;
    for(int i=0; i<n2-1; i++){
        int x;
        cin>>x;
        Node* curr=new Node(x); // rest of the nodes
        temp2->next=curr;
        temp2=temp2->next;
    }
    Node* sum=add(head1, head2);
    Node* temp=sum;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}