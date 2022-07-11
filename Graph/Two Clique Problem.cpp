/*
here we need 2 components that are connected within each other. we know that in bipartite , 
we have 2 sets in which no node is connected to each other within the same set. if we take 
complement of the graph and check bipartitie , then we have 2 such sets but it is of complemented
graph and in the original graph , each set will have nodes connected with each other.
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n , m;
vector<vector<int>>adj;
vector<vector<int>>rev_adj;

bool possible = true;
    
void dfs(int src,int par,vector<bool> &visited,vector<int> &color){
    visited[src] = true;
    if(par == -1) color[src] = 1;
    else if(color[par] == 1) color[src] = -1;
    else color[src] = 1;
    for(auto neigh : rev_adj[src]){
        if(color[neigh] == color[src]){
            possible = false; return;
        }
    }
    for(auto neigh : rev_adj[src]){
        if(!visited[neigh]) dfs(neigh,src,visited,color);
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    rev_adj.resize(n);
    for(int i = 0; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 0; i < n ; i ++){
        for(int neigh = 0; neigh < n; neigh ++){
            if(neigh == i or find(adj[i].begin(),adj[i].end(),neigh) != adj[i].end()){
                continue;
            }else rev_adj[i].push_back(neigh);
        }
    }
    vector<bool>visited(n,false);
    vector<int>color(n);
    for(int i = 0; i < n; i ++){
        if(!visited[i]) dfs(i,-1,visited,color);
    }
    if(possible) cout << "can be divided into 2 clique" << endl;
    else cout << "cannot be divided into 2 clique" << endl;
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