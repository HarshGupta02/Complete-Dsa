#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

// selects the kth smallest element in an unsorted array.
int Partition(vector<int> &a, int left, int right){
    int i = left, j = right;    
    int pivot = a[left];
    while(i < j){
        while(a[i] <= pivot) i ++;
        while(a[j] > pivot) j --;
        if(i < j) swap(a[i], a[j]);
    }
    swap(a[left], a[j]);
    return j;
}

int QuickSelect(vector<int> &a, int left, int right, int k){
    int pivot = Partition(a, left, right);
    if(k > pivot) return QuickSelect(a, pivot + 1, right, k);
    else if(k < pivot) return QuickSelect(a, left, pivot - 1, k);
    else return a[pivot];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    cout << QuickSelect(a, 0, n - 1, k - 1) << nline;
    return 0;
}