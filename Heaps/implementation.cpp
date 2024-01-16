#include<bits/stdc++.h>
using namespace std;

// class Heap{
// public:
//     int arr[100];
//     int size;

//     Heap() {
//         size = 0;
//     }

//     void insert(int val) {
//         size = size + 1;
//         int idx = size;
//         arr[idx] = val;
//         while(idx > 1) {
//             int par = idx/2;
//             if(arr[par] < arr[idx]) swap(arr[par], arr[idx]);
//             idx = par;
//         }
//     }

//     void print() {
//         for(int i = 1; i <= size; i ++) cout << arr[i] << " ";
//         cout << endl;
//     }

//     void deleteFromHeap() {
//         if(size == 0) {
//             cout << "nothing to delete" << endl;
//             return;
//         }
//         arr[1] = arr[size];
//         size --;
//         int i = 1;
//         while(i < size) {
//             int left = 2*i, right = 2*i + 1;
//             if(left <= size and arr[i] < arr[left] and arr[left] > arr[right]) {
//                 swap(arr[i], arr[left]);
//                 i = left;
//             }else if(right <= size and arr[i] < arr[right] and arr[right] > arr[left]) {
//                 swap(arr[i], arr[right]);
//                 i = right;
//             }else return;
//         }
//     }

// };

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i, right = 2*i + 1;
    if(left <= n and arr[largest] < arr[left]) largest = left;
    if(right <= n and arr[largest] < arr[right]) largest = right;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, i);
    }
}

void heapSort(int heap[], int n) {
    int size = n;
    while(size > 1) {
        swap(heap[size], heap[1]);
        size --;
        heapify(heap, size, 1);
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
    int heap[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i --) {
        heapify(heap, n, i);
    }
    // for(int i = 1; i < n; i ++) cout << heap[i] << " ";
    // cout << endl;
    heapSort(heap, n);
    for(int i = 1; i <= n; i ++) cout << heap[i] << " ";
    cout << endl;
    return 0;
}