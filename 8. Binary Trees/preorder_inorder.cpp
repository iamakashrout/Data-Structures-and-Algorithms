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

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

Node* build(vector<int>&pre, vector<int>&in, int preS, int preE, int inS, int inE){
    if(preS>preE){
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++){
        if(in[i]==rootData){
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftInS;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;
    int rightInS = rootIndex + 1;
    int rightInE = inE;
    Node *root = new Node(rootData);
    root->left = build(pre, in, leftPreS, leftPreE, leftInS, leftInE);
    root->right = build(pre, in, rightPreS, rightPreE, rightInS, rightInE);
    return root;
}

Node* buildTree(vector<int>&pre, vector<int>&in){
    return build(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
}

int main(){
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    Node *tree = buildTree(pre, in);
    levelOrder(tree);
    return 0;
}