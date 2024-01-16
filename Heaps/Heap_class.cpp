#include<bits/stdc++.h>
using namespace std;

class Heap{
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    // O(LOG N)

    void insert(int val) {
        size ++;
        arr[size] = val;
        int idx = size;
        while(idx > 1) {
            int parent = idx/2;
            if(arr[parent] < arr[idx]) swap(arr[parent], arr[idx]);
            else break;
        }
    }

    // O(LOG N)

    void deleteFromHeap() {
        if(size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size --;
        int i = 1;
        while(i < size) {
            int leftIdx = 2*i, rightIdx = 2*i + 1;
            int swapIdx = i;
            if(leftIdx <= size and arr[swapIdx] < arr[leftIdx]) swapIdx = leftIdx;
            if(rightIdx <= size and arr[swapIdx] < arr[rightIdx]) swapIdx = rightIdx;
            if(i != swapIdx) {
                swap(arr[i], arr[swapIdx]);
                i = swapIdx;
            }else return;
        }
    }

    void print() {
        for(int i = 1; i <= size; i ++) cout << arr[i] << " ";
        cout << endl;
    }
};

// O(N)

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i, right = 2*i + 1;
    if(left <= n and arr[largest] < arr[left]) largest = left;
    if(right <= n and arr[largest] < arr[right]) largest = right;
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// O(N LOGN)

void heapSort(vector<int> &arr, int n) {
    int size = n;
    while(size > 1) {
        swap(arr[size], arr[1]);
        size --;
        heapify(arr, size, 1);
    }
}

int main(){
    // Heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    vector<int> heap = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // for(int i = n/2; i > 0; i --) {
    //     heapify(heap, n, i);
    // }
    // for(int i = 1; i < n; i ++) {
    //     cout << heap[i] << " ";
    // }
    heapSort(heap, n);
    for(int i = 1; i <= n; i ++) cout << heap[i] << " ";
    cout << endl;
    return 0;
}