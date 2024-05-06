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

Node* findIntersection(Node* head1, Node* head2){
    int lenA=0, lenB=0;
    Node* tempA=head1;
    Node* tempB=head2;
    // find the longer list and move to point from where both have equal remaining length
    while(tempA!=NULL){
        lenA++;
        tempA=tempA->next;
    }
    while(tempB!=NULL){
        lenB++;
        tempB=tempB->next;
    }
    tempA=head1;
    tempB=head2;
    if(lenA>lenB){
        int diff=lenA-lenB;
        while(diff>0){
            tempA=tempA->next;
            diff--;
        }
    }
    else if(lenA<lenB){
        int diff=lenB-lenA;
        while(diff>0){
            tempB=tempB->next;
            diff--;
        }
    }
    while(tempA!=NULL && tempB!=NULL){
        if(tempA==tempB){ // find common node
            return tempA;
        }
        tempA=tempA->next;
        tempB=tempB->next;
    }
    return NULL;
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
    // common part
    int n3;
    cin>>n3;
    int first3;
    cin>>first3;
    Node* head3=new Node(first3); // create first node
    Node* temp3=head3;
    for(int i=0; i<n3-1; i++){
        int x;
        cin>>x;
        Node* curr=new Node(x); // rest of the nodes
        temp3->next=curr;
        temp3=temp3->next;
    }
    temp1->next=head3;
    temp2->next=head3;
    Node* ans=findIntersection(head1, head2);
    cout<<ans->data<<endl;
    return 0;
}