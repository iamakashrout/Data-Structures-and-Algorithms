#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> diameter_and_height(Node* root){
    if(root==NULL){
        pair<int, int> p;
        p.first = 0; // height
        p.second = 0; // diameter
        return p;
    }
    pair<int, int> left = diameter_and_height(root->left);
    pair<int, int> right = diameter_and_height(root->right);
    int height = 1 + max(left.first, right.first);
    int diameter = max(left.first + right.first, max(left.second, right.second));
    // diameter is max of individual diamters of left and right subtree (not taking root) and sum of their heights (taking root)
    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;
    return ans;
}

int main(){
    int n;
    cin >> n;
    Node *root = new Node(n);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int l;
        cin >> l;
        if (l != -1)
        {
            curr->left = new Node(l);
            q.push(curr->left);
        }
        int r;
        cin >> r;
        if (r != -1)
        {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    pair<int, int> ans = diameter_and_height(root);
    cout << "Height: " << ans.first << endl;
    cout << "Diameter: " << ans.second << endl;
    return 0;
}