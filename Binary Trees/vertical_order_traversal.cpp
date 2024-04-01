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

// print nodes at each horizontal position from top to bottom

vector<int> verticalOrderTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q; // stores node and its position
    q.push({root, 0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        mp[curr.second].push_back(curr.first->data); // add node value to its position array
        if(curr.first->left){
            q.push({curr.first->left, curr.second-1});
        }
        if(curr.first->right){
            q.push({curr.first->right, curr.second+1});
        }
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            ans.push_back(it->second[i]);
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
    vector<int> vertical=verticalOrderTraversal(root);
    for(int i=0; i<vertical.size(); i++){
        cout<<vertical[i]<<" ";
    }
    cout<<endl;
    return 0;
}