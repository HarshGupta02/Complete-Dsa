#include<bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree{
public:
    int MAXN;
    vector<int> tree, arr, lazy;
    SegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        arr = nums;
        tree.resize(4 * MAXN);
        lazy.resize(4 * MAXN, 0);
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
    void pushdown(int l, int r, int v) {
        if(l != r) {
            lazy[2*v + 1] += lazy[v];
            lazy[2*v + 2] += lazy[v];
        }
        tree[v] += (r - l + 1) * lazy[v];
        lazy[v] = 0;
    }
    void range_update(int x, int y, int val, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return;
        if(l >= x and r <= y) {
            lazy[v] = val;
            pushdown(l, r, v);
            return;
        }
        int m = (l + r)/2;
        range_update(x, y, val, l, m, 2*v + 1);
        range_update(x, y, val, m + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }
    int point_query(int idx, int l, int r, int v) {
        pushdown(l, r, v);
        if(l == r) return tree[v];
        int m = (l + r)/2;
        if(idx <= m) return point_query(idx, l, m, 2*v + 1);
        return point_query(idx, m + 1, r, 2*v + 2);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    SegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    while(q --) {
        int t;
        cin >> t;
        if(t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a --; b --;
            seg.range_update(a, b, u, 0, n - 1, 0);
        }else {
            int k;
            cin >> k; 
            k --;
            cout << seg.point_query(k, 0, n - 1, 0) << "\n";
        }
    }
    return 0;
}