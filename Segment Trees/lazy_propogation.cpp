#include<bits/stdc++.h>
using namespace std;

class LazySegmentTree{
public:
    int MAXN;
    vector<int> tree, arr, lazy;
    LazySegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN, 0);
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
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }
    int query(int x, int y, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        return (query(x, y, l, m, 2*v + 1) + query(x, y, m + 1, r, 2*v + 2));
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    LazySegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    cout << seg.query(1, 3, 0, n - 1, 0) << "\n";
    seg.update(1, 5, 10, 0, n - 1, 0);
    cout << seg.query(1, 3, 0, n - 1, 0) << "\n";
    return 0;
}