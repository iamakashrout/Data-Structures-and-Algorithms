#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// check if binary tree is a heap

bool checkHeap(Node* root){
    queue<Node*> q;
    q.push(root);
    int flag=0; // check for completeness
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->left){
            if(flag==1){ // if previous node was incomplete, return false
                return false;
            }
            if(curr->left->data>curr->data){ // child cannot have greater value than parent
                return false;
            }
            q.push(curr->left);
        }
        else{
            flag=1; // mark node as incomplete if child does not exist
        }
        if(curr->right){ // same for right node
            if(flag==1){
                return false;
            }
            if(curr->right->data>curr->data){
                return false;
            }
            q.push(curr->right);
        }
        else{
            flag=1;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    Node *root = new Node(n);
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        int l;
        cin >> l;
        if(l!=-1){
            curr->left = new Node(l);
            q.push(curr->left);
        }
        int r;
        cin >> r;
        if(r!=-1){
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    if(checkHeap(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}