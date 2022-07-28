// max-heap

/*
extract max = here we take the root element and then swap it with the min element and then we decrease
the array size by 1 and then max heapify the root.

TIME = O(LOG N) , SPACE = O(LOG N)
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

int heap_extract_max(vector<int>a){
    int n = a.size();
    if(n < 1) return -1; // underflow
    int nax = a[0]; // as root is max element in a max heap.
    swap(a[0] , a[n - 1]);
    n -= 1;
    max_heapify(a,0);
    return nax;
}

/*
increase key = here we increase the value of a particular node and this may disturb the max heap of above
nodes so we need to move the updated node up the tree so that max heap is satisfied and here it is 
sure that the tree below the updated node will never change.

TIME = O(LOG N) , SPACE = O(1)
*/

void heap_increase_key(vector<int>a,int i , int key){
    if(key < a[i]) return;
    a[i] = key;
    int par = ceil((double)i/2) - 1;
    while(i > 0 and a[par] < a[i]){ // percolate up algo
        swap(a[par],a[i]);
        i = par;
        par = ceil((double)i/2) - 1;
    }
}

/*
decrease key = here we decrease the value of a particular node and it is sure that the updated node will
only move down and try to maintain the max heap.

TIME = O(LOG N) , SPACE = O(LOG N).
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

void heap_decrease_key(vector<int>a , int i , int key){
    if(key > a[i]) return;
    a[i] = key;
    max_heapify(a,i); // percolate down
}

/*
insert element = in a complete binary tree , an element is always added at the end of the tree or at the 
last level and from left to right. and then again apply percolate up algorithm.

TIME = O(LOG N) , SPACE = O(1)
*/

void heap_insert_element(vector<int>a , int val){
    a.push_back(val); // insert the element at the last of the tree.
    int n = a.size();
    int i = n - 1;
    int par = ceil((double)i/2) - 1;
    while(i > 0 and a[par] < a[i]){
        swap(a[i] , a[par]);
        i = par;
        par = ceil((double)i/2) - 1;
    }
}