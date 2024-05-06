#include<bits/stdc++.h>
using namespace std;

// check if duplicate subtrees of size greater than or equal to 2 exist

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

string solve(Node* root, map<string, int>& mp){
    if(root==NULL){
        return "$";
    }
    string s="";
    if(root->left==NULL && root->right==NULL){ // single node
        s=to_string(root->data);
        return s;
    }
    // encoding into string
    s=s+to_string(root->data)+'.';
    s=s+solve(root->left, mp)+'.';
    s=s+solve(root->right, mp)+'.';
    mp[s]++;
    return s;
}

bool checkDuplicate(Node* root, map<string, int>& mp){
    solve(root, mp); // find count of each subtree
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second>=2){ // if count>=2, then return true
            return true;
        }
    }
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
    map<string, int> mp; // store subtrees as strings in map
    if(checkDuplicate(root, mp)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}