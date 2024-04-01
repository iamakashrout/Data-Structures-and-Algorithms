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

// find path of a node with value x from root node

bool getPath(Node* root, int x, vector<int>& path){
    if(root==NULL){
        return false; // x not found
    }
    path.push_back(root->data); // add node to path
    if(root->data==x){
        return true;
    }
    if(getPath(root->left, x, path) || getPath(root->right, x, path)){ // check for left and right nodes
        return true;
    }
    path.pop_back(); // node cant be taken in path
    return false;
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
    int x;
    cin>>x;
    vector<int> path;
    if(getPath(root, x, path)){
        cout<<"Found"<<endl;
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}