#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define debug(x) cout<< #x <<" = "; _print(x); cout <<endl
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(double t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}"; cout << endl;}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}


int n, m;
vector<vector<char>>grid;
vector<vector<int>>degree;
vector<vector<bool>>seen, seen_q;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool isSafe(int x, int y){
    return(x >= 0 and x < n and y >= 0 and y < m);
}

void solve(){
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    degree.resize(n, vector<int>(m, 0));
    seen.resize(n, vector<bool>(m, false));
    seen_q.resize(n, vector<bool>(m, false));
    for(int i = 0; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> grid[i][j];
            if(grid[i][j] == '^') {
                seen[i][j] = true; continue;    
            }
            if(grid[i][j] == '#') continue;
            grid[i][j] = '^';
        }
    }

    for(int i = 0; i < n ;i ++){
        for(int j = 0; j < m; j ++){
            if(grid[i][j] == '#') continue;
            for(int k = 0; k < 4; k ++){
                int new_x = i + dx[k], new_y = j + dy[k];
                if(isSafe(new_x, new_y) and grid[new_x][new_y] == '^') degree[i][j] ++;
            }
        }
    }

    queue<pair<int,int>>q;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(degree[i][j] == 1) q.push({i, j});
        }
    }
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        int curr_x = curr.first, curr_y = curr.second;
        seen_q[curr_x][curr_y] = true;
        degree[curr_x][curr_y] = 0;
        for(int i = 0; i < 4; i ++){
            int new_x = curr_x + dx[i], new_y = curr_y + dy[i];
            if(isSafe(new_x, new_y) and !seen_q[new_x][new_y] and grid[new_x][new_y] != '#') {
                seen_q[new_x][new_y] = true;
                degree[new_x][new_y] --;
                if(degree[new_x][new_y] == 1) q.push({new_x, new_y});
            }
        }
    }

    bool possible = true;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(seen[i][j] == true and degree[i][j] < 2){
                possible = false; break;
            }
        }
        if(!possible) break;
    }
    if(!possible) {
        // cout << "Impossible" << nline;
        cout << "Case #" << test_case << ": Impossible" << nline;
        return;
    }

    cout << "Case #" << test_case << ": Possible" << nline;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(grid[i][j] == '#') cout << "#";
            else if(degree[i][j] >= 2) cout << "^";
            else cout << ".";
        }
        cout << nline;
    }

}

int main() {
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
        seen.clear(); grid.clear();
        degree.clear(); seen_q.clear();
    }
    return 0;
}