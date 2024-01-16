#include<bits/stdc++.h>
using namespace std;
#define int long long int
using vi = vector<int>;

class SegmentTree{
public:
    int MAXN;
    vector<vi> tree;
    vi arr;
    SegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN);
        arr = nums;
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v] = {arr[l]};
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v] = Merge(tree[2*v + 1], tree[2*v + 2]);
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            tree[v] = {val};
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v] = Merge(tree[2*v + 1], tree[2*v + 2]);
    }
    int query(int x, int y, int l, int r, int v, int k) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) {
            int sz = tree[v].size();
            int idx = upper_bound(tree[v].begin(), tree[v].end(), k - 1) - tree[v].begin();
            return sz - idx;
        }
        int m = (l + r)/2;
        int left = query(x, y, l, m, 2*v + 1, k);
        int right = query(x, y, m + 1, r, 2*v + 2, k);
        return left + right;
    }
    vi Merge(vi &a, vi &b) {
        vi c;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n and j < m) {
            if(a[i] <= b[j]) {
                c.push_back(a[i]);
                i ++;
            }else {
                c.push_back(b[j]);
                j ++;
            }
        }
        while(i < n) c.push_back(a[i ++]);
        while(j < m) c.push_back(b[j ++]);
        return c;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    SegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    int q;
    cin >> q;
    while(q --) {
        int t;
        cin >> t;
        if(t == 0) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << seg.query(a - 1, b - 1, 0, n - 1, 0, c) << "\n";
        }else {
            int a, b;
            cin >> a >> b;
            seg.update(a - 1, b, 0, n - 1, 0);
        }
    }
    return 0;
}