#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    k = min(k, n);
    int idx = n - 1, val = a[n - 1];
    if(val > n) {
        cout << "No\n";
        return;
    }
    while(k --) {
        int p = (idx - val) + n;
        if(p < 0) {
            cout << "No\n"; 
            return;
        }
        idx = p % n;
        val = a[idx];
        if(val > n) {
            cout << "No\n";
            return;
        }
    }
    int p = (idx - val) + n;
    if(p < 0) cout << "No\n";
    else cout << "Yes\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}