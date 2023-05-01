/// modified version of finding count of numbers smaller than each element
// on the left or the right.

/*
here we try to make the elemnts sorted and then for traversing from left to
right, we query on (pos + 1 to n - 1) and we get the sum in the range and after
getting the sum, we update the current index by 1 notifying it's presence that
it is visited.
*/

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
        tree.resize(4*MAXN, 0);
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
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    map<ll, ll> mp;
    for(int i = 0; i < n; i ++) mp[v[i].first] = i;
    SegmentTree seg;
    ll result = 0;
    // result = count_greater_left * count_smaller_right;
    for(int j = 0; j < n; j ++) {
        int pos = mp[a[j]]; // this is the position in original sorted form
        ll greater_in_left = seg.Query(pos + 1, n - 1, 0, n - 1, 0);
        ll smaller_in_left = j - greater_in_left;
        ll smaller_in_right = pos - smaller_in_left;
        result += greater_in_left * smaller_in_right;
        seg.Update(pos, 1, 0, n - 1, 0);
    }
    cout << result << endl;
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