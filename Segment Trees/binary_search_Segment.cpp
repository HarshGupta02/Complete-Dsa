#include<bits/stdc++.h>
using namespace std;

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
    int query(int l, int r, int v, int x) {
        if(l == r) return l;
        int m = (l + r)/2;
        int left = tree[2*v + 1], right = tree[2*v + 2];
        if(left < x) return query(m + 1, r, 2*v + 2, x - left);
        return query(l, m, 2*v + 1, x);
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    SegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    while(q --) {
        int t;
        cin >> t;
        if(t == 2) {
            int x;
            cin >> x;
            cout << seg.query(0, n - 1, 0, x) << endl;
        }else {
            int idx, val;
            cin >> idx >> val;
            seg.update(idx, val, 0, n - 1, 0);
        }
    }
    return 0;
}