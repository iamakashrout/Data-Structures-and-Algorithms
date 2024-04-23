#include<bits/stdc++.h>
using namespace std;

// remove duplicate nodes in linked list, keep only 1st occurrence

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

Node* removeDuplicates(Node* head){
    map<int, int> mp; // contains nodes already appeared
    Node* temp=new Node(-1);
    Node* ans=temp;
    while(head!=NULL){
        if(mp[head->data]==0){ // if appearing for 1st time, add to answer, else skip
            temp->next=new Node(head->data);
            temp=temp->next;
            mp[head->data]++;
        }
        head=head->next;
    }
    return ans->next;
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
    Node* ans=removeDuplicates(head);
    Node* temp1=ans;
    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
    return 0;
}