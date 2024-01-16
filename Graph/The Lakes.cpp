#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int n, m;
vector<vector<int>> grid, seen;

void dfs(int x, int y, int &curr) {
    seen[x][y] = 1;
    curr += grid[x][y];
    for(int k = 0; k < 4; k ++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m and !seen[nx][ny] and grid[nx][ny] != 0) {
            dfs(nx, ny, curr);
        }
    }
}

void solve(){
    grid.clear(); seen.clear();
    cin >> n >> m;
    grid.resize(n, vector<int> (m));
    seen.resize(n, vector<int> (m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(grid[i][j] == 0 or seen[i][j]) continue;
            int curr = 0;
            dfs(i, j, curr);
            ans = max(ans, curr);
        }
    }
    cout << ans << "\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}