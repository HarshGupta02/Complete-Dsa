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
    int query(int x, int y, int l, int r, int v, int k) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) {
            int idx = upper_bound(tree[v].begin(), tree[v].end(), k) - tree[v].begin();
            return idx;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i ++) cin >> nums[i];
    SegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    int mini = *min_element(nums.begin(), nums.end());
    int maxi = *max_element(nums.begin(), nums.end());
    sort(nums.begin(), nums.end());
    // coordinate compression as all values are distinct
    for(int i = 0; i < n; i ++) mp[i] = nums[i];
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        int low = 0, high = n - 1;
        while(low < high) {
            int mid = low + (high - low)/2;
            int cnt = seg.query(a - 1, b - 1, 0, n - 1, 0, mp[mid]);
            if(cnt < c) low = mid + 1;
            else high = mid;
        }
        cout << mp[low] << "\n";
    }
    return 0;
}