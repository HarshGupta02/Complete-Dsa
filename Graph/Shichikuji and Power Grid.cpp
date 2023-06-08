#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n); rank.resize(n, 1);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }

    int get_parent(int a) {
        return (parent[a] == a ? a : get_parent(parent[a]));
    }

    void mergee(int a, int b) {
        a = get_parent(a);
        b = get_parent(b);
        if(rank[b] < rank[a]) {
            parent[b] = a;
        }else if(rank[a] < rank[b]) {
            parent[a] = b;
        }else {
            parent[b] = a;
            rank[a] ++;
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> cities(n + 1);
    for(int i = 1; i <= n; i ++) cin >> cities[i].first >> cities[i].second;
    vector<int> c(n + 1), k(n + 1);
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 1; i <= n; i ++) cin >> k[i];
    vector<array<ll,3>> edges;
    for(int i = 1; i <= n; i ++) edges.push_back({c[i], 0, i});
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            ll w = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            ll cost = (ll)w * (k[i] + k[j]);
            edges.push_back({cost, i, j});
        }
    }
    DSU dsu(n + 1);
    sort(edges.begin(), edges.end());
    ll cost = 0;
    vector<int> stations;
    vector<pair<int, int>> connections;
    for(auto it : edges) {
        int w = it[0], u = it[1], v = it[2];
        if(dsu.get_parent(u) != dsu.get_parent(v)) {
            cost += w;
            dsu.mergee(u, v);
            if(u == 0 or v == 0) stations.push_back(max(u, v));
            else connections.push_back({u, v});
        }
    }
    cout << cost << endl;
    cout << stations.size() << endl;
    for(auto it : stations) cout << it << " ";
    cout << endl;
    cout << connections.size() << endl;
    for(auto it : connections) cout << it.first << " " << it.second << endl;
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