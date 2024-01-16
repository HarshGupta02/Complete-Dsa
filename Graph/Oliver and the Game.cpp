/*

here we find the lca of both x and y and if it is x and type = 0 so yes else if
lca of x and y is y and type = 1 then also yes else no.

lca was found using binary lifting.

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

int n;
vector<vector<int>>adj;
vector<vector<int>>up;
vector<int>depth;
const int MAXN = 1e5 + 5;
const int LOGN = 14;

void dfs(int a){
    for(auto neigh : adj[a]){
        depth[neigh] = depth[a] + 1;
        up[neigh][0] = a;
        for(int j = 1; j < LOGN ; j ++){
            up[neigh][j] = up[ up[neigh][j - 1] ][j - 1];
        }
        dfs(neigh);
    }
}

int lca(int a , int b){
    if(depth[a] < depth[b]) swap(a,b);
    int k = depth[a] - depth[b];
    for(int j = LOGN - 1 ; j >= 0 ; j --){
        if(k & (1 << j)){
            a = up[a][j];
        }
    }
    if(a == b) return a;
    for(int j = LOGN - 1; j >= 0 ; j --){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve(){
    cin >> n;
    adj.resize(MAXN); depth.resize(MAXN);
    up.resize(MAXN,vector<int>(LOGN));
    for(int i = 0; i < n - 1; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1);
    int q;
    cin >> q;
    while(q --){
        int type , X , Y;
        cin >> type >> X >> Y;
        if((lca(X , Y) == X and type == 0) or (lca(X , Y) == Y and type == 1)){
            cout << "YES" << nline;
        }else cout << "NO" << nline;
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

[9,8,7,0,5,6,1,3,2,2]
1
6   