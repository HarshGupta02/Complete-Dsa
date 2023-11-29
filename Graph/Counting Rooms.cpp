#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> seen;

void dfs(int x, int y) {
    seen[x][y] = true;
    for(int k = 0; k < 4; k ++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m and !seen[nx][ny] and grid[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    grid.resize(n, vector<char> (m));
    seen.resize(n, vector<bool> (m, false));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(seen[i][j] or grid[i][j] == '#') continue;
            cnt ++;
            dfs(i, j);
        }
    }
    cout << cnt << endl;
    return 0;
}