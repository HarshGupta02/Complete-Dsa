#include<bits/stdc++.h>
using namespace std;
#define int long long int

class LazySegmentTree{
public:
    int MAXN;
    vector<int> tree, arr, lazy;
    LazySegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN);
        lazy.resize(4 * MAXN, 0);
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
        tree[v] = min(tree[2*v + 1], tree[2*v + 2]);
    }
    void pushdown(int l, int r, int v) {
        if(l != r) {
            lazy[2*v + 1] += lazy[v];
            lazy[2*v + 2] += lazy[v];
        }
        tree[v] += lazy[v];
        lazy[v] = 0;
    }
    void update(int x, int y, int val, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return;
        if(l >= x and r <= y) {
            lazy[v] = val;
            pushdown(l, r, v);
            return;
        }
        int m = (l + r)/2;
        update(x, y, val, l, m, 2*v + 1);
        update(x, y, val, m + 1, r, 2*v + 2);
        tree[v] = min(tree[2*v + 1], tree[2*v + 2]);
    }
    int query(int x, int y, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return 1e18;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        return min(query(x, y, l, m, 2*v + 1), query(x, y, m + 1, r, 2*v + 2));
    }
};

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    LazySegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    int q;
    cin >> q;
    while(q --) {
        int t, l, r;
        cin >> t >> l >> r;
        // rmq
        if(t == 0) {
            if(l <= r) cout << seg.query(l, r, 0, n - 1, 0) << "\n";
            else {
                int a = seg.query(l, n - 1, 0, n - 1, 0);
                int b = seg.query(0, r, 0, n - 1, 0);
                cout << min(a, b) << "\n";
            }
        }else { 
            int v;
            cin >> v;
            if(l <= r) seg.update(l, r, v, 0, n - 1, 0);
            else {
                seg.update(l, n - 1, v, 0, n - 1, 0);
                seg.update(0, r, v, 0, n - 1, 0);
            }
        }
    }
    return 0;
}