#include<bits/stdc++.h>
using namespace std;

// Morris Traversal: Traversing binary tree without recurison or stack

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

vector<int> morrisInorder(Node* root){
    vector<int> inOrder;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){ // if no left child, then print node
            inOrder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right && prev->right!=curr){ // move to the rigtmost node of left subtree
                prev=prev->right;
            }
            if(prev->right==NULL){
                // connect the rightmost node of left subtree to root to maintain inorder and continue left
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL; // if already connected remove connection and print root
                inOrder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inOrder;
}

vector<int> morrisPreorder(Node* root){
    vector<int> preOrder;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){ // if no left child, then print node
            preOrder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right && prev->right!=curr){ // move to the rigtmost node of left subtree
                prev=prev->right;
            }
            if(prev->right==NULL){
                // connect the rightmost node of left subtree to root to maintain inorder and continue left
                prev->right=curr;
                preOrder.push_back(curr->data); // print node before moving to left child
                curr=curr->left;
            }
            else{
                prev->right=NULL; // if connection already present, move to right subtree
                curr=curr->right;
            }
        }
    }
    return preOrder;
}

vector<int> morrisPostorder(Node* root){
    vector<int> postOrder; // to be filled in reverse order
    Node* curr=root;
    while(curr!=NULL){
        if(curr->right==NULL){ // if no right child, then print node
            postOrder.push_back(curr->data);
            curr=curr->left;
        }
        else{
            Node* prev=curr->right;
            while(prev->left && prev->left!=curr){ // move to the leftmost node of right subtree
                prev=prev->left;
            }
            if(prev->left==NULL){
                // connect the leftmost node of right subtree to root to maintain inorder and continue right
                prev->left=curr;
                postOrder.push_back(curr->data); // print node before moving to right child
                curr=curr->right;
            }
            else{
                prev->left=NULL; // if connection already present, move to left subtree
                curr=curr->left;
            }
        }
    }
    reverse(postOrder.begin(), postOrder.end());
    return postOrder;
}

int main(){
    int n;
    cin >> n; // value of root
    Node *root = new Node(n);
    queue<Node *> q; // take input of children for all nodes, -1 means no child
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
    vector<int> inOrder=morrisInorder(root);
    for(int i=0; i<inOrder.size(); i++){
        cout<<inOrder[i]<<" ";
    }
    cout<<endl;
    vector<int> preOrder=morrisPreorder(root);
    for(int i=0; i<preOrder.size(); i++){
        cout<<preOrder[i]<<" ";
    }
    cout<<endl;
    vector<int> postOrder=morrisPostorder(root);
    for(int i=0; i<postOrder.size(); i++){
        cout<<postOrder[i]<<" ";
    }
    cout<<endl;
    return 0;
}