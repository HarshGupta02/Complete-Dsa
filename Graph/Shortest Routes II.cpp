#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

int n, m, q;
vector<vector<int>> dist;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    dist.resize(n, vector<int> (n, 1e18));
    for(int i = 0; i < n; i ++) dist[i][i] = 0;
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --; b --;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for(int k = 0; k < n; k ++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(dist[i][k] == 1e18 or dist[k][j] == 1e18)
                    continue;
                if(dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    while(q --) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        int ans = dist[u][v];
        if(ans == 1e18) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}