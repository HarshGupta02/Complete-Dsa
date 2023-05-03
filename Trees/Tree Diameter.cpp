/*
so either the longest path will pass through the root or will not
pass through the root so we consider both the cases. if the path does not
passes through the root so we take the max diameter of all the childs of 
the root and return ans else if the path passes throught the root then 
we do 2 + (sum of max_depth of childs of the root).
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

static const int MAXN = 2e5 + 5;
int depth[MAXN];
int diameter[MAXN];
vector<vector<ll>> adj;

void max_depth(int src, int par) {
    int leaf = 1, best_depth = 0;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        leaf = 0;
        max_depth(neigh, src);
        best_depth = max(best_depth, depth[neigh]);
    }
    if(leaf) depth[src] = 0;
    else depth[src] = 1 + best_depth;
}

void f(int src, int par) {
    int ans = 0;
    vector<int> child_depths;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        f(neigh, src);
        child_depths.push_back(depth[neigh]);
        ans = max(ans, diameter[neigh]);
    }
    int m = child_depths.size();
    if(m == 0) diameter[src] = 0;
    else if(m == 1) diameter[src] = 1 + child_depths[0];
    else {
        sort(child_depths.begin(), child_depths.end());
        diameter[src] = 2 + child_depths[m - 1] + child_depths[m - 2];
    }
    diameter[src] = max(diameter[src], ans);
}

void solve(){
    int n;
    cin >> n;
    adj.clear(); adj.resize(n);
    memset(depth, 0, sizeof(depth));
    memset(diameter, 0, sizeof(diameter));
    for(int i = 0; i < n - 1; i ++) {
        ll a, b;
        cin >> a >> b;
        a --; b --;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    max_depth(1, -1);
    f(1, -1);
    cout << diameter[1] << endl;
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