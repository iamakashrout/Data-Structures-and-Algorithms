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

Node* mergeTwoLists(Node* a, Node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    // take smaller head value of a and b and merge the remaining with the other linked list
    if(a->data<=b->data){
        Node* ans=a;
        ans->next=mergeTwoLists(a->next, b);
        return ans;
    }
    else{
        Node* ans=b;
        ans->next=mergeTwoLists(a, b->next);
        return ans;
    }
    return NULL;
}

Node* mergeKLists(vector<Node*>& a, int k){
    Node* ans=a[0]; // answer linked list
    for(int i=1; i<k; i++){
        ans=mergeTwoLists(ans, a[i]); // merge every linked list in array with answer step by step
    }
    return ans;
}

int main(){
    int k;
    cin>>k;
    vector<Node*> a(k);
    for(int i=0; i<k; i++){
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
        a[i]=head;
    }
    Node* ans=mergeKLists(a, k);
    Node* temp=ans;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}