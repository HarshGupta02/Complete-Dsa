using ll = long long int;
class SegmentTree{
public:
    static const int MAXN = 1e5 + 4;
    vector<int> tree;
    
    SegmentTree(){
        tree.resize(4 * MAXN, 0);
    }
    
    void Update(int idx, int new_val, int l, int r, int v) {
        if(l == r) {
            tree[v] = new_val;
            return;
        }
        int mid = (l + r)/2;
        if(idx <= mid) Update(idx, new_val, l, mid, 2*v + 1);
        else Update(idx, new_val, mid + 1, r, 2*v + 2);
        tree[v] = max(tree[2*v + 1], tree[2*v + 2]);
    }
    
    ll Query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        int mid = (l + r)/2;
        return max(Query(x, y, l, mid, 2*v + 1), Query(x, y, mid + 1, r, 2*v + 2));
    }
    
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i ++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        map<int, int> pos;
        for(int i = 0; i < n; i ++) pos[v[i].second] = i;
        SegmentTree seg;
        for(int i = 0; i < n; i ++) {
            int idx = lower_bound(v.begin(), v.end(), make_pair(nums[i], -1)) - v.begin();
            int val = 1 + (idx > 0 ? seg.Query(0, idx - 1, 0, n - 1, 0) : 0);
            seg.Update(pos[i], val, 0, n - 1, 0);
        }
        return seg.Query(0, n - 1, 0, n - 1, 0);
    }
};