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
vector<vector<int>> timer_a, timer_m;
vector<vector<Coordinate>> path;
string ans = "";
bool possible = false;

void go(int x, int y) {
    if(x == sx and y == sy) return;
    ans.push_back(path[x][y].ch);
    go(path[x][y].x, path[x][y].y);
}

void print(vector<vector<int>> & g) {
    for(int i = 0; i < g.size(); i ++) {
        for(int j = 0; j < g[0].size(); j ++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &seen, int choice) {
    while(!q.empty()) {
        int sz = q.size();
        while(sz --) {
            int cx = q.front().first, cy = q.front().second; q.pop();
            for(int k = 0; k < 4; k ++) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if(nx >= 0 and nx < n and ny >= 0 and ny < m and !seen[nx][ny] and grid[nx][ny] != '#') {
                    if(choice == 0) {
                        timer_a[nx][ny] = 1 + timer_a[cx][cy];
                        seen[nx][ny] = true;
                        q.push({nx, ny});
                    }else if(choice == 1) {
                        timer_m[nx][ny] = min(timer_m[nx][ny], 1 + timer_m[cx][cy]);
                        seen[nx][ny] = true;
                        q.push({nx, ny});
                    }else {
                        if(timer_a[nx][ny] < timer_m[nx][ny]) {
                            path[nx][ny] = Coordinate(cx, cy, dir[k]);
                            if(nx == 0 or nx == n - 1 or ny == 0 or ny == m - 1) {
                                tx = nx; ty = ny;
                                possible = true;
                                return;
                            }
                            seen[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    grid.resize(n, vector<char> (m));
    vector<vector<bool>> seen_a(n, vector<bool> (m, false));
    vector<vector<bool>> seen_m(n, vector<bool> (m, false));
    vector<vector<bool>> seen_final(n, vector<bool> (m, false));
    timer_a.resize(n, vector<int> (m, 0));
    timer_m.resize(n, vector<int> (m, INT_MAX));
    path.resize(n, vector<Coordinate> (m));

    queue<pair<int, int>> q_a, q_m, q_final;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                sx = i; sy = j;
                q_a.push({sx, sy});
                timer_a[sx][sy] = 0;
                seen_a[sx][sy] = true;
            }
            if(grid[i][j] == 'M') {
                q_m.push({i, j});
                timer_m[i][j] = 0;
                seen_m[i][j] = true;
            }
        }
    }

    if(sx == 0 or sx == n - 1 or sy == 0 or sy == m - 1) {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }

    q_final.push({sx, sy});
    bfs(q_a, seen_a, 0);
    bfs(q_m, seen_m, 1);
    bfs(q_final, seen_final, 2);

    if(!possible) {
        cout << "NO\n";
        return 0;
    }
    
    go(tx, ty);
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << (int) ans.size() << "\n";
    cout << ans << "\n";
    return 0;
}