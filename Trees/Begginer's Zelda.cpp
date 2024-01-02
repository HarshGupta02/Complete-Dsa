#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

void solve(){
    int n;
    cin >> n;
    int degree[n + 1]{0};
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        degree[u] ++; degree[v] ++;
    }
    int leaf = 0;
    for(int i = 1; i <= n; i ++) {
        if(degree[i] == 1) leaf ++;
    }
    if(leaf % 2 == 1) cout << leaf/2 + 1 << "\n";
    else cout << leaf/2 << "\n";
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