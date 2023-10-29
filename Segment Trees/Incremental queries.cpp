#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node{
    int maxi, sum, even, odd;
    Node(){}
    Node(int maxi, int sum, int even, int odd) {
        this -> maxi = maxi;
        this -> sum = sum;
        this -> even = even;
        this -> odd = odd;
    }
};

class SegmentTree{
public:
    int MAXN;
    vector<Node> tree;
    vector<int> arr;
    SegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        tree.resize(4 * MAXN);
        arr = nums;
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v].maxi = arr[l];
            tree[v].sum = arr[l];
            tree[v].even = arr[l] % 2 == 0 ? 1 : 0;
            tree[v].odd = arr[l] % 2 != 0 ? 1 : 0;
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v].maxi = max(tree[2*v + 1].maxi, tree[2*v + 2].maxi);
        tree[v].sum = tree[2*v + 1].sum + tree[2*v + 2].sum;
        tree[v].even = tree[2*v + 1].even + tree[2*v + 2].even;
        tree[v].odd = tree[2*v + 1].odd + tree[2*v + 2].odd;
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            tree[v].maxi = val;
            tree[v].sum = val;
            tree[v].even = val % 2 == 0 ? 1 : 0;
            tree[v].odd = val % 2 != 0 ? 1 : 0;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v].maxi = max(tree[2*v + 1].maxi, tree[2*v + 2].maxi);
        tree[v].sum = tree[2*v + 1].sum + tree[2*v + 2].sum;
        tree[v].even = tree[2*v + 1].even + tree[2*v + 2].even;
        tree[v].odd = tree[2*v + 1].odd + tree[2*v + 2].odd;
    }
    Node query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return Node(-1e18, 0, 0, 0);
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        Node left = query(x, y, l, m, 2*v + 1);
        Node right = query(x, y, m + 1, r, 2*v + 2);
        Node ans;
        ans.maxi = max(left.maxi, right.maxi);
        ans.sum = left.sum + right.sum;
        ans.even = left.even + right.even;
        ans.odd = left.odd + right.odd;
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
        else {
            Node curr = seg.query(a - 1, b - 1, 0, n - 1, 0);
            int maxi = curr.maxi, sum = curr.sum;
            int even = curr.even, odd = curr.odd;
            int len = b - a + 1;
            int diff = maxi * len - sum;
            if(maxi % 2 == 0) cout << diff/2 + (odd + 1)/2 << "\n";
            else cout << diff/2 + (even + 1)/2 << "\n";
        }
    }
    return 0;
}