#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
 
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
char dir[4] = {'L', 'U', 'R', 'D'};
 
struct Coordinate{
    int x, y;
    char ch;
    Coordinate(){}
    Coordinate(int x, int y, char ch) {
        this -> x = x;
        this -> y = y;
        this -> ch = ch;
    }
};
 
int n, m, sx, sy, tx, ty;
vector<vector<char>> grid;
vector<vector<bool>> seen;
vector<vector<Coordinate>> path;
int mini = INT_MAX;
string ans = "";
bool possible = false;
 
void go(int x, int y) {
    if(x == sx and y == sy) return;
    ans.push_back(path[x][y].ch);
    go(path[x][y].x, path[x][y].y);
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    grid.resize(n, vector<char> (m));
    seen.resize(n, vector<bool> (m, false));
    path.resize(n, vector<Coordinate> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if(grid[i][j] == 'B') {
                tx = i;
                ty = j;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({sx, sy});
    seen[sx][sy] = true;
    while(!q.empty()) {
        int sz = q.size();
        while(sz --) {
            int cx = q.front().first, cy = q.front().second; q.pop();
            for(int k = 0; k < 4; k ++) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if(nx >= 0 and nx < n and ny >= 0 and ny < m and !seen[nx][ny] and grid[nx][ny] != '#') {
                    seen[nx][ny] = true;
                    path[nx][ny] = Coordinate(cx, cy, dir[k]);
                    q.push({nx, ny});
                }
            }
        }
    }
    if(!seen[tx][ty]) {
        cout << "NO\n";
        return 0;
    }
    go(tx, ty);
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << (int)ans.size() << "\n";
    cout << ans << "\n";
    return 0;
