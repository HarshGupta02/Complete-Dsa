#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class SegmentTree{
public:
    static const int MAXN = 2e5 + 5;
    vector<ll> tree, arr;
    SegmentTree(vector<ll> nums) {
        tree.resize(4 * MAXN);
        arr = nums;
    }

    void Build(int l, int r, int v) {
        if(l == r) {
            tree[v] = arr[l];
            return;
        }
        ll mid = (l + r)/2;
        Build(l, mid, 2*v + 1);
        Build(mid + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }

    void Update(int idx, int new_val, int l, int r, int v) {
        if(l == r) {
            tree[v] = new_val;
            return;
        }
        ll mid = (l + r)/2;
        if(idx <= mid) Update(idx, new_val, l, mid, 2*v + 1);
        else Update(idx, new_val, mid + 1, r, 2*v + 2);
        tree[v] = tree[2*v + 1] + tree[2*v + 2];
    }

    ll Query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        ll mid = (l + r)/2;
        return Query(x, y, l, mid, 2*v + 1) + Query(x, y, mid + 1, r, 2*v + 2);
    }

};

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    SegmentTree seg(a);
    seg.Build(0, n - 1, 0);
    while(q --) {
        ll type, a, b;
        cin >> type >> a >> b;
        if(type == 1) seg.Update(a - 1, b, 0, n - 1, 0);
        else cout << seg.Query(a - 1, b - 1, 0, n - 1, 0) << endl;
    }
}

int main() {
    fast_cin();
    ll test_cases = 1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}