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

vector<vector<int>> zigZagTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){ // level order traversal
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
        ans.push_back(temp);
    }
    for(int i=0; i<ans.size(); i++){ // reverse every second level
        if(i%2==1){
            reverse(ans[i].begin(), ans[i].end());
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
    vector<vector<int>> zigZag=zigZagTraversal(root);
    for(int i=0; i<zigZag.size(); i++){
        for(int j=0; j<zigZag[i].size(); j++){
            cout<<zigZag[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}