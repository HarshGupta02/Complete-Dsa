#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>>adj(n); // 1 based 
    for(int i = 0; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u); // bidirectional graph
    }
    for(int i = 0 ; i < n ; i ++){
        cout << i << " ------> ";
        for(auto it : adj[i]){
            cout << it << " -----> ";
        }
        cout << endl;
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


// GFG QUES:

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<vector<int>>g(V);
        for(int i = 0 ; i < V; i ++){
            g[i].push_back(i);
            for(auto it : adj[i]){
                g[i].push_back(it);
            }
        }
        return g;
    }
};