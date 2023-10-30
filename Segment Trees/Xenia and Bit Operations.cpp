#include<bits/stdc++.h>
using namespace std;
#define int long long int

class SegmentTree{
public:
    int MAXN;
    vector<int> tree, arr;
    SegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN);
        arr = nums;
    }
    void build(int l, int r, int v, int op) {
        if(l == r) {
            tree[v] = arr[l];
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1, !op);
        build(m + 1, r, 2*v + 2, !op);
        if(op) tree[v] = (tree[2*v + 1] | tree[2*v + 2]);
        else tree[v] = (tree[2*v + 1] ^ tree[2*v + 2]);
    }
    void update(int idx, int val, int l, int r, int v, int op) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1, !op);
        else update(idx, val, m + 1, r, 2*v + 2, !op);
        if(op) tree[v] = (tree[2*v + 1] | tree[2*v + 2]);
        else tree[v] = (tree[2*v + 1] ^ tree[2*v + 2]);
    }
    int query(int x, int y, int l, int r, int v, int op) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        int left = query(x, y, l, m, 2*v + 1, !op);
        int right = query(x, y, m + 1, r, 2*v + 2, !op);
        if(op) return (left | right);
        return (left ^ right);
    }
};

signed main(){
    int n, m;
    cin >> n >> m;
    n = (1 << n);
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    int height = (int)ceil(log2(n));
    int op = -1;
    if(height % 2 == 0) op = 0;
    else op = 1;
    SegmentTree seg(n, arr);
    seg.build(0, n - 1, 0, op);
    for(int i = 0; i < m; i ++) {
        int p, b;
        cin >> p >> b;
        seg.update(p - 1, b, 0, n - 1, 0, op);
        cout << seg.query(0, n - 1, 0, n - 1, 0, op) << "\n";
    }
    return 0;
}