#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node{
    int val;
    Node* left, *right;
    Node(int val) {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

class PersistentSegmentTree{
public:
    int n;
    vector<Node*> roots;
    PersistentSegmentTree(int _n) {
        n = _n;
        roots.push_back(buildInitialTree(0, n - 1));
    }
    void UpdateValue(int idx, int val) {
        roots.push_back(buildNewtree(roots.back(), idx, val, 0, n - 1));
    }
    int Query(int idx, int l, int r) {
        return query(l, r, 0, n - 1, roots[idx]);
    }
    Node* buildInitialTree(int l, int r) {
        if(l == r) return new Node(0);
        int m = (l + r)/2;
        Node* result = new Node(0);
        result->left = buildInitialTree(l, m);
        result->right = buildInitialTree(m + 1, r);
        return result;
    }
    Node* buildNewtree(Node* prev_root, int idx, int val, int l, int r) {
        if(l == r) return new Node(val);
        int m = (l + r)/2;
        Node* result = new Node(0);
        if(idx <= m) {
            result -> left = buildNewtree(prev_root -> left, idx, val, l, m);
            result -> right = prev_root -> right;
        }else {
            result -> left = prev_root -> left;
            result -> right = buildNewtree(prev_root -> right, idx, val, m + 1, r);
        }
        result -> val = result -> left -> val + result -> right -> val;
        return result;
    }
    int query(int x, int y, int l, int r, Node* root) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return root -> val;
        int m = (l + r)/2;
        int left_ans = query(x, y, l, m, root -> left);
        int right_ans = query(x, y, m + 1, r, root -> right);
        return left_ans + right_ans;
    }
};

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i ++) arr.push_back({nums[i], i});
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i ++) mp[arr[i].second] = i;
    PersistentSegmentTree seg(n);
    for(int i = 0; i < n; i ++) seg.UpdateValue(mp[i], 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        int idx = upper_bound(arr.begin(), arr.end(), make_pair(c, -1), cmp) - arr.begin();
        if(idx >= n) {
            cout << "0\n";
            continue;
        }
        cout << seg.Query(b, idx, n - 1) - seg.Query(a - 1, idx, n - 1) << "\n";
    }
    return 0;
}