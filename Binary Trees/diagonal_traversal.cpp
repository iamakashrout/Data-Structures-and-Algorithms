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

// print all nodes in same diagonal line for all diagonals

vector<int> diagonalTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        while(curr!=NULL){
            if(curr->left){ // if left node exists, add to queue
                q.push(curr->left);
            }
            ans.push_back(curr->data); // print value
            curr=curr->right; // move to right node
        }
    }
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
    vector<int> diagonal=diagonalTraversal(root);
    for(int i=0; i<diagonal.size(); i++){
        cout<<diagonal[i]<<" ";
    }
    cout<<endl;
    return 0;
}