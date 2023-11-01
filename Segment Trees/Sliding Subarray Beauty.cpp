class SegmentTree{
public:
    int MAXN;
    vector<int> tree;
    SegmentTree(int n) {
        MAXN = n;
        tree.resize(4 * MAXN);
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v] = 0;
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

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        const int MAXN = 101;
        SegmentTree seg(MAXN);
        seg.build(0, MAXN - 1, 0);
        unordered_map<int, int> mp;
        for(int i = 0; i <= k - 2; i ++) {
            int idx = nums[i] + 50;
            mp[idx] ++;
            seg.update(idx, mp[idx], 0, MAXN - 1, 0);
        }
        vector<int> ans;
        for(int i = k - 1; i < n; i ++) {
            int idx1 = nums[i] + 50, idx2 = nums[i - k + 1] + 50;
            mp[idx1] ++;
            seg.update(idx1, mp[idx1], 0, MAXN - 1, 0);
            int res = seg.query(0, MAXN - 1, 0, x);
            int actual = res - 50;
            if(actual >= 0) ans.push_back(0);
            else ans.push_back(actual);
            mp[idx2] --;
            seg.update(idx2, mp[idx2], 0, MAXN - 1, 0);
        }
        return ans;
    }
};