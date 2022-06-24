/// find the pivot index (min element index in a rotated sorted array).

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n ; i ++) cin >> a[i];
    int low = 0, high = n - 1;
    int idx = -1;
    while(high - low > 1){
        int mid = low + (high - low)/2 ;
        if(a[low] < a[mid] and a[mid] < a[high]){
            idx = low; break;
        }
        if(a[low] < a[mid]) low = mid;
        else high = mid;
    }
    if(idx == -1){
        if(a[low] < a[high]) idx = low;
        else idx = high;
    }
    cout << idx << nline;
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


// 2 3 5 7 12      {2,5,12}
// 12 2 3 5 7      {12,3,7}    
// 7 12 2 3 5      {7,2,5}
// 5 7 12 2 3      {5,12,3}
// 3 5 7 12 2      {3,7,2}

