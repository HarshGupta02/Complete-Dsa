#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
 
int n;
vector<vector<int>> adj;
vector<int> ans;
 
int dfs(int src){
    int cnt = 1;
    for(auto neigh : adj[src]) cnt += dfs(neigh);
    ans[src] = cnt;
    return cnt;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    adj.resize(n + 1);
    ans.resize(n + 1);
    for(int i = 0; i < n - 1; i ++){
        int x; cin >> x;
        adj[x].push_back(i + 2);
    }
    int total = dfs(1);
    for(int i = 1; i <= n; i ++) cout << ans[i] - 1 << " ";
    cout << "\n";
    return 0;
}