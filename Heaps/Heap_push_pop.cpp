#include<bits/stdc++.h>
using namespace std;
#define nline endl;
const int MAXN = 1001;

vector<int>heap;
int heapSize = 0;

void max_heapify(vector<int> &heap, int curr , int sz){
    int l = 2 * curr + 1;
    int r = 2 * curr + 2;
    int largest;
    if(l < sz and heap[l] > heap[curr]) largest = l;
    else largest = curr;
    if(r < sz and heap[r] > heap[largest]) largest = r;
    if(largest != curr){
        swap(heap[curr] , heap[largest]);
        max_heapify(heap,largest,sz);
    }
}

void heap_push(int val){
    if(heapSize >= MAXN){
        cout << "overflow" << nline;
        return;
    }
    heap[heapSize] = val;
    int curr = heapSize;
    int par = ceil((double) curr/2) - 1;
    while(curr > 0 and heap[par] < heap[curr]){
        swap(heap[par],heap[curr]);
        curr = par;
        par = ceil((double) curr/2) - 1;
    }
    heapSize ++;
}

int heap_pop(){
    if(heapSize <= 0){
        cout << "underflow" << nline;
        return -1;
    }
    int popped = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize -= 1;
    max_heapify(heap,0,heapSize);
    return popped;
}

int main(){
    heap.resize(MAXN);
    heap_push(12);
    heap_push(3);
    heap_push(4);
    heap_push(18);
    heap_push(1);
    int x = heap_pop();
    x = heap_pop();
    x = heap_pop();
    for(int i = 0; i < heapSize; i ++){
        cout << heap[i] << " ";
    }
    return 0;
}