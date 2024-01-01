/*

naive time = O(N^2*LOGN)

so this DSU on trees. so this is a technique of small to
large merging. so we maintain a vector of pointers to 
sets. so for a node, we take that node that has max size
of set. then we point the curr src node set pointer to the
max child set. then also we point all the childs of the src
to the max size set node. so kind of union by rank or
size. 

NOW TIME = O(N*LOGN*LOGN) (how ??)

*/

#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int n;
vector<int> colors;
vector<vector<int>> adj;
vector<set<int> *> st;
vector<int> ans;

void dfs(int src, int par) {
    int max_size = -1, max_node;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        dfs(neigh, src);
        int curr_set_size = st[neigh] -> size();
        if(curr_set_size > max_size) {
            max_size = curr_set_size;
            max_node = neigh;
        }
    }
    if(max_size == -1) st[src] = new set<int> ();
    else st[src] = st[max_node];
    st[src] -> insert(colors[src]);
    for(auto neigh : adj[src]) {
        if(neigh == par or neigh == max_node) continue;
        for(auto val : *st[neigh]) 
            st[src] -> insert(val);
    }
    ans[src] = (int) st[src] -> size();
}

void solve(){
    colors.clear(); adj.clear();
    st.clear(); ans.clear();
    cin >> n;
    colors.resize(n + 1); adj.resize(n + 1);
    st.resize(n + 1); ans.resize(n + 1, 0);
    for(int i = 1; i <= n; i ++) cin >> colors[i];
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i ++) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    fast_cin();
    int test_cases = 1;
    // cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}