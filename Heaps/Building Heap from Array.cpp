#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void max_heapify(vector<int>& heap, int curr , int sz){
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int largest;
    if(left < sz and heap[left] > heap[curr]) largest = left;
    else largest = curr;
    if(right < sz and heap[right] > heap[largest]) largest = right;
    if(largest != curr){
        swap(heap[curr] , heap[largest]);
        max_heapify(heap, largest , sz);
    }
}

void solve(){   
    int n;
    cin >> n;
    vector<int>heap;
    for(int i = 0; i < n ; i ++){
        int x;
        cin >> x;
        heap.push_back(x);
    }

    // build 

    for(int i = (heap.size()/2) - 1; i >= 0; i --){
        max_heapify(heap,i,heap.size());
    }

    for(auto it : heap) cout << it << " ";
    cout << nline;
}

int main() {
    fast_cin();
    ll test_cases = 1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}