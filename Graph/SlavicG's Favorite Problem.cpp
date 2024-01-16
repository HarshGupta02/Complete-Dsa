#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;
const int LOG = 30;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, a, b;
vector<vector<pair<int, int>>> adj;
set<int> st;

void dfs1(int src, int par, int till_now_xorr) {
    if(src == b) return;
    st.insert(till_now_xorr);
    for(auto neigh : adj[src]) {
        int child = neigh.first, w = neigh.second;
        if(child == par) continue;
        dfs1(child, src, till_now_xorr ^ w);
    }
}

bool dfs2(int src, int par, int till_now_xorr) {
    if(src != b and st.count(till_now_xorr) > 0) return true;
    for(auto neigh : adj[src]) {
        int child = neigh.first, w = neigh.second;
        if(child == par) continue;
        if(dfs2(child, src, till_now_xorr ^ w)) return true;
    }
    return false;
}

void solve(){
    cin >> n >> a >> b;
    adj.resize(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int xorr = 0;
    dfs1(a, -1, xorr);
    if(dfs2(b, -1, xorr)) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        st.clear(); adj.clear();
        solve();
    }
    return 0;
}