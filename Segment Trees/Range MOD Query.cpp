#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = 1e9 + 7;

int fast_exp(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res % MOD;
}

struct Node{
    int mini, sum;
    Node(){}
    Node(int mini, int sum) {
        this -> mini = mini;
        this -> sum = sum;
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
            tree[v].mini = arr[l];
            tree[v].sum = arr[l] == 1e18 ? 0 : arr[l];
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v].mini = min(tree[2*v + 1].mini, tree[2*v + 2].mini);
        tree[v].sum = (tree[2*v + 1].sum + tree[2*v + 2].sum) % MOD;
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            if(tree[v].mini == 1e18) {
                tree[v].mini = ;
                tree[v].sum = val;
            }
            return;
        }
        int m = (l + r)/2;
        if(idx <= m) update(idx, val, l, m, 2*v + 1);
        else update(idx, val, m + 1, r, 2*v + 2);
        tree[v].mini = min(tree[2*v + 1].mini, tree[2*v + 2].mini);
        tree[v].sum = (tree[2*v + 1].sum + tree[2*v + 2].sum) % MOD;
    }
    Node query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return Node(1e18, 0);
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        Node left = query(x, y, l, m, 2*v + 1);
        Node right = query(x, y, m + 1, r, 2*v + 2);
        Node ans;
        ans.mini = min(left.mini, right.mini);
        ans.sum = (left.sum + right.sum) % MOD;
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) 
        arr[i] = s[i] == '1' ? (1 << (n - i - 1)) % MOD : 1e18;
    SegmentTree seg(n, arr);
    seg.build(0, n - 1, 0);
    for(int i = 0; i < q; i ++) {
        int t;
        cin >> t;
        if(t == 1) {
            int idx;
            cin >> idx; idx --;
            seg.update(idx, -1, 0, n - 1, 0);
            // if(arr[idx] != 1e18) seg.update(idx, 1e18, 0, n - 1, 0);
            // else seg.update(idx, (1 << i) % MOD, 0, n - 1, 0);
        }else {
            int a, b;
            cin >> a >> b;
            Node curr = seg.query(a - 1, b - 1, 0, n - 1, 0);
            int p = fast_exp(curr.mini, MOD - 2);
            cout << (curr.sum * p) % MOD << "\n";
        }
    }
    return 0;
}