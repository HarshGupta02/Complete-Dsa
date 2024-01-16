#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

class SegmentTree1{
public:
    int MAXN;
    vector<int> tree, arr;
    SegmentTree1(int n, vector<int> &nums) {
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
        tree[v] = max(tree[2*v + 1], tree[2*v + 2]);
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v] = max(tree[2*v + 1], tree[2*v + 2]);
    }
    int query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return -1e18;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        int ans = max(query(x, y, l, m, 2*v + 1), query(x, y, m + 1, r, 2*v + 2));
        return ans;
    }
};

class SegmentTree2{
public:
    int MAXN;
    vector<int> tree, arr;
    SegmentTree2(int n, vector<int> &nums) {
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
        tree[v] = min(tree[2*v + 1], tree[2*v + 2]);
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v] = min(tree[2*v + 1], tree[2*v + 2]);
    }
    int query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return 1e18;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        int ans = min(query(x, y, l, m, 2*v + 1), query(x, y, m + 1, r, 2*v + 2));
        return ans;
    }
};

int m;

int go(int l, int r, vector<int> &a, SegmentTree1 &seg1, SegmentTree2 &seg2) {
    if(l >= r) return 0;
    int ans = 0;
    int mid = l + (r - l)/2;
    int m = a.size();
    int left_min = seg2.query(l, mid, 0, m - 1, 0);
    int left_max = seg1.query(l, mid, 0, m - 1, 0);
    int right_min = seg2.query(mid + 1, r, 0, m - 1, 0);
    int right_max = seg1.query(mid + 1, r, 0, m - 1, 0);
    if(left_max >= right_min and left_max <= right_max) return INT_MAX;
    if(right_max >= left_min and right_max <= left_max) return INT_MAX;
    if(left_min >= right_max) ans ++;
    int left_op = go(l, mid, a, seg1, seg2);
    int right_op = go(mid + 1, r, a, seg1, seg2);
    ans += (left_op + right_op);
    return ans;
}

void solve(){
    cin >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i ++) cin >> a[i];
    SegmentTree1 seg1(m, a); seg1.build(0, m - 1, 0);
    SegmentTree2 seg2(m, a); seg2.build(0, m - 1, 0);
    int res = go(0, m - 1, a, seg1, seg2);
    if(res >= INT_MAX) res = -1;
    cout << res << "\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}