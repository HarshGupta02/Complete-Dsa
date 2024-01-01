#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

class SegmentTree{
public:
    int MAXN;
    vector<int> tree, arr;
    SegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN);
        arr = nums;
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v] = arr[l];
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }
    int sum(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        int ans = sum(x, y, l, m, 2*v + 1) + sum(x, y, m + 1, r, 2*v + 2);
        return ans;
    }
};

int n, q, m, timer;
vector<vector<int>> adj;
vector<int> in, out, euler, val;

void dfs(int src, int par) {
    in[src] = timer;
    euler[timer ++] = val[src];
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        dfs(neigh, src);
    }
    out[src] = timer;
    euler[timer ++] = -1 * val[src];
}

void solve(){
    adj.clear(); in.clear(); out.clear();
    val.clear(); euler.clear();
    cin >> n >> q;
    m = 2*n + 1; timer = 1;
    adj.resize(n + 1); in.resize(n + 1); out.resize(n + 1);
    euler.resize(m); val.resize(n + 1);
    for(int i = 1; i <= n; i ++) cin >> val[i];
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    SegmentTree seg(m, euler);
    seg.build(1, m - 1, 0);
    for(int i = 0; i < q; i ++) {
        int type;
        cin >> type;
        if(type == 1) {
            int s, x;
            cin >> s >> x;
            seg.update(in[s], x, 1, m - 1, 0);
            seg.update(out[s], -x, 1, m - 1, 0);
        }else {
            int s;
            cin >> s;
            cout << seg.sum(1, in[s], 1, m - 1, 0) << "\n";
        }
    }
}

signed main() {
    fast_cin();
    int test_cases = 1;
    // cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}