/// TIME = O(N * LOGN) , SPACE = O(LOG N)

#include<bits/stdc++.h>
using namespace std;

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

void Heap_Sort(vector<int> &heap){
    // build heap
    for(int i = (heap.size()/2) - 1; i >= 0 ; i --){
        max_heapify(heap,i,heap.size());
    }

    /*
    after building the max heap , we will use the extract max algo and place it in it's correct place and
    then max_heapify the root and we will do the extract max algo for all the n nodes so that each element
    is in it's correct place and in the end we obtain the array in ascending order.
    */

    // after each iteration , the heap size will decrease.
    for(int i = heap.size() - 1; i >= 0 ; --i){  // i is the current size of the heap.
        swap(heap[0], heap[i]);
        // before heapify , we need to decrease the size of the heap.
        max_heapify(heap,0,i);
    }
}

int main(){
    int n ;
    cin >> n;
    vector<int>heap(n);
    for(int i = 0; i < n ; i ++){
        cin >> heap[i];
    }    
    Heap_Sort(heap);
    for(auto it : heap){
        cout << it << " ";
    }
    return 0;
}