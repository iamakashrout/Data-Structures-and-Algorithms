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

// find subtree with maximum sum of node values

int solve(Node* root, int& ans){
    if(root==NULL){
        return 0;
    }
    // replace node value with sum of subtree
    root->data=root->data+solve(root->left, ans)+solve(root->right, ans);
    ans=max(ans, root->data); // update ans
    return root->data;
}

int largestSubtreeSum(Node* root){
    int ans=INT_MIN;
    solve(root, ans);
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
    int ans=largestSubtreeSum(root);
    cout<<ans<<endl;
    return 0;
}