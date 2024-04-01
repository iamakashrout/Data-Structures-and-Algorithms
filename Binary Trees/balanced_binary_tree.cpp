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

int height(Node* root){ // height of tree
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    // difference between height of left subtree and right subtree should be less than or equal to 1
    // both left and right subtrees should be balanced
    int diff=abs(height(root->left)-height(root->right));
    return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
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
    if(isBalanced(root)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}