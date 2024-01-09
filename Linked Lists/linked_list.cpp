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

class LinkedList{
public:
    Node *head;
    LinkedList(){
        head=NULL;
    }
    
    void print(){ // PRINT A LINKED LIST
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void add(int val){ // ADD ELEMENT TO END
        Node *new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

    void remove(int val){ // REMOVE ELEMENT WITH GIVEN VALUE
        Node* temp=head;
        while(temp->next!=NULL && temp->next->data!=val){
            temp=temp->next;
        }
        if(temp->next && temp->next->data==val){
            Node* x=temp->next;
            temp->next=temp->next->next;
            delete x;
        }
    }

    void reverse(){ // REVERSE A LINKED LIST
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
};

int main(){
    LinkedList head;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        head.add(x);
    }
    head.print();
    head.reverse();
    head.print();
    int m;
    cin>>m;
    head.remove(m);
    head.print();
    return 0;
}