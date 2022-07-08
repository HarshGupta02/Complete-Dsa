#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<int>> adj;
vector<bool>visited;

void dfs(int src,int &ans){
    visited[src] = true; ans ++;
    for(auto neigh : adj[src]){
        if(!visited[neigh]) dfs(neigh,ans);
    }
}

void solve(){
    ll n , p;
    cin >> n >> p;
    adj.resize(n);
    for(int i = 0; i < p ; i ++){
        ll u , v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    visited.resize(n,false);
    ll res = 0;
    for(int i = 0; i < n ; i ++){
        if(!visited[i]){
            int cnt = 0;
            dfs(i,cnt);
            res += (n - cnt) * cnt;
        }
    }
    cout << res / 2<< nline;
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