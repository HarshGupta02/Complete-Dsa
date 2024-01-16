#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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

void QuickSort(vector<int> &a, int left, int right){
    if(left >= right) return;
    int pivot = Partition(a,left,right);
    QuickSort(a, left, pivot - 1);
    QuickSort(a, pivot + 1, right);
}

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n ; i ++) cin >> a[i];
    QuickSort(a, 0, n - 1);
    for(auto it : a) cout << it << " ";
    cout << endl;
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