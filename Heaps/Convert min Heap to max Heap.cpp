// METHOD 1: TIME = O(N * LOGN)

// here we percolate up , all the nodes.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n); for(int i = 0 ; i < n ; i ++) cin >> a[i];
    for(int i = 0; i < n ; i ++){
        // percolate up;
        int curr = i;
        int par = ceil((double)curr/2) - 1;
        while(curr > 0 and a[par] < a[curr]){
            swap(a[par], a[curr]);
            curr = par;
            par = ceil((double)curr/2) - 1;
        }
    }
    for(auto it : a) cout << it << " ";
    cout << endl;
    return 0;
}

// METHOD 2: 

void max_heapify(long *a ,int curr, int n){
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int largest;
    if(left < n and a[left] > a[curr]) largest = left;
    else largest = curr;
    if(right < n and a[right] > a[largest]) largest = right;
    if(largest != curr){
        swap(a[curr] , a[largest]);
        max_heapify(a, largest, n);
    }
}

void minHeapToMaxHeap(long *a, int n)
{
    for(int i = (n/2) - 1; i >= 0; i --){
        max_heapify(a,i,n);
    }
}