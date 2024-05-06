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

class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }

    private: // adding a node in BST
    Node* insert(Node* root, int data){
        if(root==NULL){
            Node *newNode = new Node(data);
            return newNode;
        }
        if(root->data>=data){
            root->left = insert(root->left, data);
        }
        else if(root->data<data){
            root->right = insert(root->right, data);
        }
        return root;
    }
    public:
    void insert(int data){
        this->root = insert(this->root, data);
    }

    private: // searching a node in BST
    bool search(Node* root, int data){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        if(root->data>data){
            return search(root->left, data);
        }
        if(root->data<data){
            return search(root->right, data);
        }
    }
    public:
    bool search(int data){
        return search(this->root, data);
    }

    private: // removing a node in BST
    Node* remove(Node* root, int data){
        if(root==NULL){
            return NULL;
        }
        if(root->data>data){
            root->left = remove(root->left, data);
            return root;
        }
        else if(root->data<data){
            root->right = remove(root->right, data);
            return root;
        }
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            if(root->left==NULL){
                Node *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else{
                Node *temp = root->left;
                while(temp->right!=NULL){
                    temp = temp->right;
                }
                root->data = temp->data;
                root->left = remove(root->left, temp->data);
                return root;
            }
        }
    }
    public:
    void remove(int data){
        this->root = remove(this->root, data);
    }


    private: // print a BST
    void print(Node* root){
        if(root==NULL){
            return;
        }
        cout << root->data <<": ";
        if(root->left!=NULL){
            cout << "L:" << root->left->data << " ";
        }
        if(root->right!=NULL){
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }
    public:
    void print(){
        print(this->root);
    }
};

int main(){
    BST bst;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        bst.insert(x);
    }
    bst.print();
    int y;
    cin >> y;
    cout << bst.search(y) << endl;
    int z;
    cin >> z;
    bst.remove(z);
    bst.print();
    return 0;
}