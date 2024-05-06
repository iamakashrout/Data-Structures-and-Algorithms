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

// maximum sum of values between any connected path of nodes

int solve(Node* root, int& ans){
    if(root==NULL){
        return 0;
    }
    int left=max(0, solve(root->left, ans)); // maximum path ending at left child
    int right=max(0, solve(root->right, ans)); // maximum path ending at right child
    ans=max(ans, root->data+left+right); // sum both paths with value of root and compare with ans
    return root->data+max(left, right); // return maximum path ending at root node
}

int maxPathSum(Node* root){
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
    int ans=maxPathSum(root);
    cout<<ans<<endl;
    return 0;
}