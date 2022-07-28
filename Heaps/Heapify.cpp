// TIME = O(LOG N) , SPACE = O(LOG N)

/*
(max_heapify) = here we assume that the entire subtree is max_heap instead of the ith node.
Here we first find the max element withing the parent , left child and the right child and then see if
it is greater than parent , then swap the parent and the largest element and then recursively max_heapify
for the largest element.

*/

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

void min_heapify(vector<int> &heap, int curr , int sz){
    int l = 2 * curr + 1;
    int r = 2 * curr + 2;
    int smallest;
    if(l < sz and heap[l] < heap[curr]) smallest = l;
    else smallest = curr;
    if(r < sz and heap[r] < heap[smallest]) smallest = r;
    if(smallest != curr){
        swap(heap[curr] , heap[smallest]);
        max_heapify(heap,smallest,sz);
    }
}