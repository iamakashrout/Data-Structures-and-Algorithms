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

// traverse the left end nodes first, then leaf nodes and finally right end nodes for all nodes in tree

bool isLeaf(Node* root){ // check if node is leaf node
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}

void left(Node* root, vector<int>& ans){ // traverse all the left end nodes
    Node* curr=root->left;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}

void leaves(Node* root, vector<int>& ans){ // traverse all leaf nodes
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left){
        leaves(root->left, ans);
    }
    if(root->right){
        leaves(root->right, ans);
    }
}

void right(Node* root, vector<int>& ans){ // traverse all right nodes
    Node* curr=root->right;
    vector<int> temp;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1; i>=0; i--){ // add to answer in reverse order
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
    left(root, ans); // left nodes
    leaves(root, ans); // leaf nodes
    right(root, ans); // right nodes
    return ans;
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
    vector<int> boundary=boundaryTraversal(root);
    for(int i=0; i<boundary.size(); i++){
        cout<<boundary[i]<<" ";
    }
    cout<<endl;
    return 0;
}