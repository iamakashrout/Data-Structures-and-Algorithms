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

void flatten(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node* prev=curr->left;
            while(prev->right){
                prev=prev->right; // find rightmost node of left subtree
            }
            prev->right=curr->right; // add the right subtree of root to its right
            curr->right=curr->left; // add the left subtree to right of root
            curr->left=NULL; // set left subtree to be null
        }
        curr=curr->right; // move to the right node of root
    }
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
    flatten(root);
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
    return 0;
}