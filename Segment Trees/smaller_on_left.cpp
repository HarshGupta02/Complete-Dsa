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
    // consider all the elements are unique
    int n;
    cin >> n;
    vector<int> arr(n), nums(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    nums = arr;
    sort(nums.begin(), nums.end());
    map<int, int> mp;
    for(int i = 0; i < n; i ++) mp[nums[i]] = i;
    vector<int> a(n, 0);
    SegmentTree seg(n, a);
    seg.build(0, n - 1, 0);
    for(int i = 0; i < n; i ++) {
        int idx = mp[arr[i]];
        cout << seg.sum(0, idx - 1, 0, n - 1, 0) << " ";
        seg.update(idx, 1, 0, n - 1, 0);
    }
    return 0;
}