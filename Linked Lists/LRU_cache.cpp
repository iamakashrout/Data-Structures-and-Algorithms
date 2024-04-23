#include<bits/stdc++.h>
using namespace std;

// Implementing Least Recently Used Cache

class LRUCache{
public:
// using Doubly Linked List nodes
    class Node{
    public:
    // stores key-value pairs and prev and next pointers
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key=k;
            val=v;
        }
    };

    Node* head=new Node(-1, -1); // beginning end of LRU Cache, new nodes added this side
    Node* tail=new Node(-1, -1); // end of LRU Cache
    int cap; // capacity of cache
    map<int, Node*> mp; // poins to node with given value

    LRUCache(int capacity){ // constructor
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode){ // adding new node to cache
        Node* temp=head->next; // current cache nodes
        newNode->next=temp; // add new node at front of cache
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode; // update pointers
    }

    void deleteNode(Node* node){ // deletes node from cache
        Node* prevNode=node->prev; // connect previous and next nodes of the node to be deleted
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    int get(int k){ // get value of key from cache
        if(mp.find(k)!=mp.end()){
            Node* res=mp[k]; // find node with key k
            int ans=res->val; // its value to be returned
            mp.erase(k); // remove from current position
            deleteNode(res);
            addNode(res); // add to top of cache
            mp[k]=head->next;
            return ans;
        }
        return -1; // if not present in cache
    }

    void put(int k, int v){ // add key value pair {k, v} to cache
        if(mp.find(k)!=mp.end()){ // if already present, remove previous occurrence
            Node* node=mp[k];
            mp.erase(k);
            deleteNode(node);
        }
        if(mp.size()==cap){ // if cache full, remove last element (Least Recently Used element)
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(k, v)); // add node to front
        mp[k]=head->next;
    }
};

int main(){
    int n;
    cin>>n;
    LRUCache lru(n);
    int ops;
    cin>>ops;
    for(int i=0; i<ops; i++){
        int op;
        cin>>op;
        if(op==1){ // add element to cache
            int k, v;
            cin>>k>>v;
            lru.put(k, v);
        }
        else if(op==2){ // get value of key from cache
            int k;
            cin>>k;
            cout<<lru.get(k)<<endl;
        }
    }
    return 0;
}