void max_heap(vector<int>& heap, int curr , int sz){
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int largest;
    if(left < sz and a[left] > a[curr]) largest = left;
    else largest = curr;
    if(right < sz and a[right] > a[largest]) largest = right;
    if(largest != curr){
        swap(a[curr] , a[largest]);
        max_heap(heap,largest,sz);
    }
}

void build_heap(vector<int>& heap){
    for(int i = heap.size()/2 - 1; i >= 0 ; i --){
        max_heap(heap,i,heap.size());
    }
}

int extract_max(vector<int>& heap){
    int maxi = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    max_heap(heap,0,heap.size());
    return maxi;
}

void increase_key(vector<int>& heap, int i , int key){
    if(heap[i] > key) return;
    heap[i] = key;
    int par = ceil((double)i/2) - 1;
    while(i > 0 and heap[par] < heap[i]){
        swap(heap[i] , heap[par]);
        i = par;
        par = ceil((double)i/2 - 1);
    }
}

void decrease_key(vector<int>& heap , int i , int key){
    if(heap[i] < key) return;
    heap[i] = key;
    max_heap(heap, i, heap.size());
}

void insert_element(vector<int>& heap, int val){
    heap.push_back(val);
    int curr = heap.size() - 1;
    int par = ceil((double)curr/2) - 1;
    while(curr > 0 and heap[par] < heap[curr]){
        swap(heap[curr] , heap[par]);
        curr = par;
        par = ceil((double)curr/2) - 1;
    }
}

/// heap sort -> 1. build heap.
// 2. for each element , max_heapify the current node.

void heapsort(vector<int>& heap){
    // build heap
    for(int i = (heap.size()/2) - 1; i >= 0 ; i --){
        max_heap(heap,i,heap.size());
    }

    for(int i = heap.size() - 1; i >= 0 ; i --){
        swap(heap[0] , heap[i]);
        max_heap(heap, 0, i);
    }
}