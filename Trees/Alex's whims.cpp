#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n - 1; i ++) {
        cout << i << " " << i + 1 << "\n";
    }
    int par = n - 1;
    while(q --) {
        int d;
        cin >> d;
        int u = n;
        int v1 = par;
        int v2 = d;
        if(v1 == v2) cout << "-1 -1 -1\n";
        else {
            cout << u << " " << v1 << " " << v2 << "\n";
            par = d;
        }
    }
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