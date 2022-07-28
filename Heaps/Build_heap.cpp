// TIME = O(N) AND NOT O(N * LOGN) , SPACE = O(LOG N)

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

/*
HERE WE HEAPIFY ALL THE INTERNAL NODES FROM THE BOTTOM BECAUSE LEAF NODES ARE ALWAYS HEAPIFIED AND TO
HEAPIFY A NODE , IT'S LEFT AND RIGHT SUBTREE MUST BE ALREADY HEAPIFIED.

RANGE OF INTERNAL NODES(0 BASED INDEXING) = 0 TO N/2 - 1.
*/


void Build_Max_Heap(vector<int>heap){
    int n = heap.size();
    for(int i = n/2 - 1; i >= 0 ; i --){
        max_heapify(heap, i, n);    
    }
}