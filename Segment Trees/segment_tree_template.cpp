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

signed main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    SegmentTree seg(n, arr);
    seg.build(0, n - 1, 0);
    for(int i = 0; i < q; i ++) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) seg.update(a - 1, b, 0, n - 1, 0);
        else cout << seg.sum(a - 1, b - 1, 0, n - 1, 0) << "\n";
    }
    return 0LL;
}