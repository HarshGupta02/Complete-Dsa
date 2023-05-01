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
    static const ll MAXN = 1e6 + 5;
    vector<ll> tree;
    SegmentTree() {
        tree.resize(4 * MAXN, 0);
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> f1(n, 0), f2(n, 0);
    map<ll, ll> mp1, mp2;
    for(int i = 0; i < n; i ++) {
        mp1[a[i]] ++;
        f1[i] = mp1[a[i]];
    }
    for(int i = n - 1; i >= 0; i --) {
        mp2[a[i]] ++;
        f2[i] = mp2[a[i]];
    }
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i ++) v[i] = {f1[i], i};
    sort(v.begin(), v.end());
    map<pair<int, int>, int> pos;
    for(int i = 0; i < n; i ++) pos[v[i]] = i;
    SegmentTree seg;
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        int f1_idx = pos[{f1[i], i}];
        int f2_idx = upper_bound(v.begin(), v.end(), {f2[i], INT_MAX}) - v.begin();
        if(f2_idx < n) res += seg.Query(f2_idx, n - 1, 0, n - 1, 0);
        seg.Update(f1_idx, 1, 0, n - 1, 0);
    }
    cout << res << endl;
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