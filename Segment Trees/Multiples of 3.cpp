#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node{
    int c0, c1, c2;
    Node(int a, int b, int c) {
        c0 = a; c1 = b; c2 = c;
    }
};

class SegmentTree{
public:
    int MAXN;
    vector<Node> tree;
    vector<int> arr, lazy;
    SegmentTree(int n, vector<int> &nums) {
        MAXN = n;
        arr = nums;
        tree.resize(4 * MAXN, Node(0, 0, 0));
        lazy.resize(4 * MAXN);
    }
    void build(int l, int r, int v) {
        if(l == r) {
            tree[v].c0 = arr[l] % 3 == 0 ? 1 : 0;
            tree[v].c1 = arr[l] % 3 == 1 ? 1 : 0;
            tree[v].c2 = arr[l] % 3 == 2 ? 1 : 0;
            return;
        }
        int m = (l + r)/2;
        build(l, m, 2*v + 1);
        build(m + 1, r, 2*v + 2);
        tree[v].c0 = tree[2*v + 1].c0 + tree[2*v + 2].c0;
        tree[v].c1 = tree[2*v + 1].c1 + tree[2*v + 2].c1;
        tree[v].c2 = tree[2*v + 1].c2 + tree[2*v + 2].c2;
    }
    void pushdown(int l, int r, int v) {
        if(l != r) {
            lazy[2*v + 1] += lazy[v];
            lazy[2*v + 2] += lazy[v];
        }
        int a = tree[v].c0, b = tree[v].c1, c = tree[v].c2;
        int d = lazy[v]; d %= 3;
        if(d == 1) {
            tree[v].c1 = a;
            tree[v].c2 = b;
            tree[v].c0 = c;
        }else if(d == 2) {
            tree[v].c2 = a;
            tree[v].c0 = b;
            tree[v].c1 = c;
        }
        lazy[v] = 0;
        return;
    }
    void update(int x, int y, int val, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return;
        if(l >= x and r <= y) {
            lazy[v] = val;
            pushdown(l, r, v);
            return;
        }
        int m = (l + r)/2;
        update(x, y, val, l, m, 2*v + 1);
        update(x, y, val, m + 1, r, 2*v + 2);
        tree[v].c0 = tree[2*v + 1].c0 + tree[2*v + 2].c0;
        tree[v].c1 = tree[2*v + 1].c1 + tree[2*v + 2].c1;
        tree[v].c2 = tree[2*v + 1].c2 + tree[2*v + 2].c2;
    }
    Node query(int x, int y, int l, int r, int v) {
        pushdown(l, r, v);
        if(r < x or l > y) return Node(0, 0, 0);
        if(l >= x and r <= y) return tree[v];
        int m = (l + r)/2;
        Node left = query(x, y, l, m, 2*v + 1);
        Node right = query(x, y, m + 1, r, 2*v + 2);
        Node curr = Node(0, 0, 0);
        curr.c0 = left.c0 + right.c0;
        curr.c1 = left.c1 + right.c1;
        curr.c2 = left.c2 + right.c2;
        return curr;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> nums(n, 0);
    SegmentTree seg(n, nums);
    seg.build(0, n - 1, 0);
    while(q --) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 0) seg.update(a, b, 1, 0, n - 1, 0);
        else cout << seg.query(a, b, 0, n - 1, 0).c0 << "\n";
    }
    return 0;
}