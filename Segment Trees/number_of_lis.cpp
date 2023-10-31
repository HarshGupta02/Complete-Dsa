#include<bits/stdc++.h>
using namespace std;
#define int long long int
using pii = pair<int, int>;
static const int MOD = 1e9 + 7;

class SegmentTree{
public:
    int MAXN;
    vector<pii> tree;
    SegmentTree(int n) {
        MAXN = n;
        tree.resize(4 * MAXN);
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v] = {0, 1};
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v] = Merge(tree[2*v + 1], tree[2*v + 2]);
    }
    void update(int idx, pii val, int l, int r, int v) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v] = Merge(tree[2*v + 1], tree[2*v + 2]);
    }
    pii query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return {0, 1};
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        pii left = query(x, y, l, m, 2*v + 1);
        pii right = query(x, y, m + 1, r, 2*v + 2);
        return Merge(left, right);
    }
    pii Merge(pii a, pii b) {
        if(a.first != b.first) return max(a, b);
        if(a.first == 0) return {0, 1};
        pii c;
        c.first = a.first; c.second = (a.second + b.second) % MOD;
        return c;
    }
};

bool cmp(const pii &a, const pii &b) {
    return a.first < b.first;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    vector<pii> arr;
    for(int i = 0; i < n; i ++) arr.push_back({nums[i], i});
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i ++) mp[arr[i].second] = i;
    SegmentTree seg(n);
    seg.build(0, n - 1, 0);
    for(int i = 0; i < n; i ++) {
        int lb = lower_bound(arr.begin(), arr.end(), make_pair(nums[i], -1), cmp) - arr.begin();
        pii res = {1, 1};
        if(lb > 0) {
            res = seg.query(0, lb - 1, 0, n - 1, 0);
            res.first ++; res.first %= MOD;
        }
        seg.update(mp[i], res, 0, n - 1, 0);
    }
    pii ans = seg.query(0, n - 1, 0, n - 1, 0);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}