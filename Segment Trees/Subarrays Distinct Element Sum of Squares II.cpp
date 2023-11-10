using ll = long long int;
static const ll MOD = 1e9 + 7;

class SegmentTree{
public:
    ll MAXN;
    vector<vector<ll>> tree;
    vector<ll> lazy;
    SegmentTree(ll n) {
        MAXN = n;
        tree.resize(4 * MAXN, vector<ll> (2));
        lazy.resize(4 * MAXN);
    }
    void pushdown(ll l, ll r, ll v) {
        if(l != r) {
            lazy[2*v + 1] += lazy[v];
            lazy[2*v + 2] += lazy[v];
        }
        tree[v][0] += (r - l + 1) * lazy[v] * lazy[v] + 2 * lazy[v] * tree[v][1]; 
        tree[v][0] %= MOD;
        tree[v][1] += (r - l + 1) * lazy[v];
        tree[v][1] %= MOD;
        lazy[v] = 0;
    }
    void update(ll x, ll y, ll val, ll l, ll r, ll v) {
        pushdown(l, r, v);
        if(r < x or l > y) return;
        if(l >= x and r <= y) {
            lazy[v] = val;
            pushdown(l, r, v);
            return;
        }
        ll m = (l + r)/2;
        update(x, y, val, l, m, 2*v + 1);
        update(x, y, val, m + 1, r, 2*v + 2);
        tree[v][0] = (tree[2*v + 1][0] + tree[2*v + 2][0]) % MOD;
        tree[v][1] = (tree[2*v + 1][1] + tree[2*v + 2][1]) % MOD;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        ll n = nums.size();
        unordered_map<ll, ll> last_seen;
        for(int i = 0; i < n; i ++) last_seen[nums[i]] = -1;
        SegmentTree seg(n);
        ll ans = 0;
        for(int i = 0; i < n; i ++) {
            ll last_seen_idx = last_seen[nums[i]];
            seg.update(last_seen_idx + 1, i, 1, 0, n - 1, 0);
            ans = (ans + seg.tree[0][0]) % MOD;
            last_seen[nums[i]] = i;
        }
        return ans;
    }
};