#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;
using vi = vector<int>;

class SegmentTree {
public:
    int MAXN;
    vector<vi> tree;
    vector<int> nums;

    SegmentTree(int n, vi &a) {
        MAXN = n;
        tree.resize(4*MAXN);
        nums = a;
    }

    vi Merge(vi &a, vi &b) {
        int n1 = a.size(), n2 = b.size();
        vi c;
        int i = 0, j = 0;
        while(i < n1 and j < n2) {
            if(a[i] <= b[j]) {
                c.push_back(a[i]);
                i ++;
            }else {
                c.push_back(b[j]);
                j ++;
            }
        }
        while(i < n1) c.push_back(a[i ++]);
        while(j < n2) c.push_back(b[j ++]);
        return c;
    }

    void build(int l, int r, int v) {
        if(l == r) {
            tree[v] = {nums[l]};
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v] = Merge(tree[2*v + 1], tree[2*v + 2]);
    }

    int query(int mini, int maxi, int x, int y, int l, int r, int v) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) {
            int left_cnt = lower_bound(tree[v].begin(), tree[v].end(), mini) - tree[v].begin();
            int right_cnt = lower_bound(tree[v].begin(), tree[v].end(), maxi) - tree[v].begin();
            return (right_cnt - left_cnt);
        }
        int m = (l + r)/2;
        int a = query(mini, maxi, x, y, l, m, 2*v + 1);
        int b = query(mini, maxi, x, y, m + 1, r, 2*v + 2);
        return (a + b);
    }

};

int n, q, timer;
vector<vector<int>> adj;
vector<int> perm, in, out;

void dfs(int src, int par) {
    in[src] = timer ++;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        dfs(neigh, src);
    }
    out[src] = timer ++;
}

void solve(){
    cin >> n >> q;
    adj.resize(n + 1); perm.resize(n + 1);
    in.resize(n + 1); out.resize(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) cin >> perm[i];
    dfs(1, -1);
    vector<int> in_timers(n + 1);
    for(int i = 1; i <= n; i ++)
        in_timers[i] = in[perm[i]];
    SegmentTree seg(n, in_timers);
    seg.build(1, n, 0);
    for(int i = 0; i < q; i ++) {
        int l, r, x;
        cin >> l >> r >> x;
        int btw = seg.query(in[x], out[x], l ,r, 1, n, 0);
        if(btw) cout << "YES\n";
        else cout << "NO\n";
    }
    cout << "\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        adj.clear(); perm.clear();
        in.clear(); out.clear(); timer = 1;
        solve();
    }
    return 0;
}