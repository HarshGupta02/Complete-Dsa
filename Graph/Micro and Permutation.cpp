#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<int>>seen(n,vector<int>(n,0));
    vector<ll>a(n);
    for(int i = 0; i < n ; i ++) a[i] = i;
    for(int i = 0; i < m ; i ++){
        ll u, v;
        cin >> u >> v;
        u --; v --;
        seen[u][v] = seen[v][u] = 1;
    }
    ll ans = 0;
    do{
        bool found = true;
        for(int i = 0; i + 1 < n ; i ++) {
            if(seen[a[i]][a[i + 1]] == 0) {
                found = false; break;
            }
        }
        if(found) ans ++;
    }while(next_permutation(a.begin(), a.end()));
    cout << ans << nline;
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