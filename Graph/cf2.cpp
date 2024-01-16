#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<int>> adj;
int diameter = 0;

int dfs(int src, int par) {
    int max_height = -1, second_max_height = -1;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        int curr_height = dfs(neigh, src);
        if(curr_height > max_height) {
            second_max_height = max_height;
            max_height = curr_height;
        }else if(curr_height > second_max_height) {
            second_max_height = curr_height;
        }
    }
    diameter = max(diameter, max_height + second_max_height + 2);
    max_height ++;
    return max_height;
}

void solve(){
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        a --; b --;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    diameter = n - diameter;
    cout << diameter/2 + 1 << "\n";
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
        adj.clear();
        diameter = 0;
    }
    return 0;
}
