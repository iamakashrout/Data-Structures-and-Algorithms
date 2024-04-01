#include<bits/stdc++.h>
using namespace std;

// nodes of binary tree seen from different directions

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

vector<int> leftView(Node* root){ // left view of binary tree
    vector<int> left;
    if(root==NULL){
        return left;
    }
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> levels; // find nodes at all levels, add the first node at each level to answer
    while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            Node* curr=q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        levels.push_back(temp);
    }
    for(int i=0; i<levels.size(); i++){
        left.push_back(levels[i][0]);
    }
    return left;
}

vector<int> rightView(Node* root){ // right view of binary tree
    vector<int> right;
    if(root==NULL){
        return right;
    }
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> levels; // find nodes at all levels, add the last node at each level to answer
    while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            Node* curr=q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        levels.push_back(temp);
    }
    for(int i=0; i<levels.size(); i++){
        right.push_back(levels[i][levels[i].size()-1]);
    }
    return right;
}

vector<int> bottomView(Node* root){ // bottom view of binary tree
    vector<int> bottom;
    if(root==NULL){
        return bottom;
    }
    // nodes at the last level would be visible at each position
    // take position of root as 0, left child as pos-1 and right child as pos+1
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        mp[curr.second]=curr.first->data; // update value at position
        if(curr.first->left){
            q.push({curr.first->left, curr.second-1});
        }
        if(curr.first->right){
            q.push({curr.first->right, curr.second+1});
        }
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        bottom.push_back(it->second); // bottom most values at each position
    }
    return bottom;
}

vector<int> topView(Node* root){ // top view of binary tree
    vector<int> top;
    if(root==NULL){
        return top;
    }
    // nodes at the first level would be visible at each position
    // take position of root as 0, left child as pos-1 and right child as pos+1
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        if(mp.find(curr.second)==mp.end()){
            mp[curr.second]=curr.first->data; // update value at position only if not previously visited
        }
        if(curr.first->left){
            q.push({curr.first->left, curr.second-1});
        }
        if(curr.first->right){
            q.push({curr.first->right, curr.second+1});
        }
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        top.push_back(it->second); // top most values at each position
    }
    return top;
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
    vector<int> left=leftView(root);
    for(int i=0; i<left.size(); i++){
        cout<<left[i]<<" ";
    }
    cout<<endl;
    vector<int> right=rightView(root);
    for(int i=0; i<right.size(); i++){
        cout<<right[i]<<" ";
    }
    cout<<endl;
    vector<int> bottom=bottomView(root);
    for(int i=0; i<bottom.size(); i++){
        cout<<bottom[i]<<" ";
    }
    cout<<endl;
    vector<int> top=topView(root);
    for(int i=0; i<top.size(); i++){
        cout<<top[i]<<" ";
    }
    cout<<endl;
    return 0;
}