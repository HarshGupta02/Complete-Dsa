using ll = long long int;
class LazySegmentTree{
public:
    int MAXN;
    vector<ll> tree, arr;
    vector<bool> lazy;
    LazySegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN, 0);
        lazy.resize(4 * MAXN, false);
        arr.resize(n);
        for(int i = 0; i < n; i ++) arr[i] = 1LL * nums[i];
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v] = arr[l] == 1 ? 1 : 0;
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }
    void pushdown(int l, int r, int v) {
        if(!lazy[v]) return;
        if(l != r) {
            lazy[2*v + 1] = lazy[2*v + 1] ^ lazy[v];
            lazy[2*v + 2] = lazy[2*v + 2] ^ lazy[v];
        }
        tree[v] = (r - l + 1) - tree[v];
        lazy[v] = false;
    }
    void update(int x, int y, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return;
        if(l >= x and r <= y) {
            lazy[v] = true;
            pushdown(l, r, v);
            return;
        }
        int m = (l + r)/2;
        update(x, y, l, m, 2*v + 1);
        update(x, y, m + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }
    ll query(int x, int y, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return 0LL;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        return (query(x, y, l, m, 2*v + 1) + query(x, y, m + 1, r, 2*v + 2));
    }
};

class Solution {
public:
    vector<ll> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        LazySegmentTree seg(n, nums1);
        seg.build(0, n - 1, 0);
        ll sum = 0, add = 0;
        for(auto it : nums2) sum += it;
        vector<ll> ans;
        for(auto q : queries) {
            ll t = q[0], a = q[1], b = q[2];
            if(t == 1) seg.update(a, b, 0, n - 1, 0);
            else if(t == 2) sum += (seg.query(0, n - 1, 0, n - 1, 0) * a);
            else ans.push_back(sum);
        }
        return ans;
    }
};