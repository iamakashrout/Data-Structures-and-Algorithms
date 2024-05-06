#include<bits/stdc++.h>
using namespace std;

int left(int k){
    return 2*k+1; // left child of node
}

int right(int k){
    return 2*k+2; // right child of node
}

int parent(int k){
    return (k-1)/2; // parent of node
}

int heapify(vector<int>& heap, int k, int& size){ // function to heapify binary tree
    int l=left(k);
    int r=right(k);
    int largest=k; // if any child is larger, update parent with larger child
    if(l<size && heap[l]>heap[largest]){
        largest=l;
    }
    if(r<size && heap[r]>heap[largest]){
        largest=r;
    }
    if(largest!=k){ // repeat for all levels below
        int temp=heap[k];
        heap[k]=heap[largest];
        heap[largest]=temp;
        heapify(heap, largest, size);
    }
}


void push(vector<int>& heap, int val, int& size){
    heap[size]=val; // push at end of heap
    int i=size;
    size++;
    // replace with parent if it is larger than parent
    while(i!=0 && heap[parent(i)]<heap[i]){
        int temp=heap[i];
        heap[i]=heap[parent(i)];
        heap[parent(i)]=temp;
        i=parent(i);
    }
}

int pop(vector<int>& heap, int& size){
    if(size==0){
        cout<<"Heap is empty!"<<endl;
        return -1;
    }
    if(size==1){
        size--;
        return heap[0];
    }
    // to remove maximum element, replace it with last element and heapify the tree
    int val=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify(heap, 0, size);
    return val;
}

int top(vector<int>& heap, int& size){
    if(size==0){
        cout<<"Heap is empty!"<<endl;
        return -1;
    }
    return heap[0];
}

void printHeap(vector<int>& heap, int& size){
    for(int i=0; i<size; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> heap(n);
    int size=0;
    for(int i=0; i<n; i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            push(heap, x, size);
            printHeap(heap, size);
        }
        else if(op==2){
            pop(heap, size);
            printHeap(heap, size);
        }
        else if(op==3){
            cout<<top(heap, size)<<endl;
        }
    }
    return 0;
}