#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        rank.resize(n, 1);
    }
    int get_parent(int a) {
        return a == parent[a] ? a : get_parent(parent[a]);
    }
    void mergee(int a, int b) {
        a = get_parent(a);
        b = get_parent(b);
        if(a == b) return;
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[a] > rank[b]) parent[b] = a;
        else {
            rank[a] ++;
            parent[b] = a;
        }
    }
};

int n, m;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        dsu.mergee(u, v);
    }
    set<int> abs_parent;
    for(int i = 0; i < n; i ++) {
        int x = dsu.get_parent(i);
        abs_parent.insert(x);
    }
    vector<int> v(abs_parent.begin(), abs_parent.end());
    cout << (int)v.size() - 1 << "\n";
    for(int i = 0; i < v.size() - 1; i ++) {
        cout << v[i] + 1 << " " << v[i + 1] + 1 << "\n";
    }
    return 0;
}