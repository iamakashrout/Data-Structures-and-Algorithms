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

// check if the value of every node is equal to the sum of values of its left and right children

bool check(Node* root){
    if(root==NULL){
        return true;
    }
    if(root->left && root->right){ // if both children present
        if(root->data!=root->left->data+root->right->data){
            return false;
        }
    }
    else if(root->left && root->data!=root->left->data){ // if only left child present
        return false;
    }
    else if(root->right && root->data!=root->right->data){ // if only right child present
        return false;
    }
    return check(root->left) && check(root->right); // check for left and right children
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
    if(check(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}