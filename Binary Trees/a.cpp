#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int n, m, sx, sy, d;

int dist(int x, int y){
    return abs(x - sx) + abs(y - sy);
}

bool isSafe(int x, int y){
    return (x >= 0 and x < n and y >= 0 and y < m and dist(x, y) > d);
}


/*

1. if the ending cell has dist <= d so -1.
2. run a bfs from laser and mark all dangerous cells as visited.
3. then run a bfs from source (1,1).

*/

void solve(){
    cin >> n >> m >> sx >> sy >> d;
    sx --; sy --;
    bool found = false;
    for(int i = 0; i < m; i ++){
        if(dist(0, i) <= d){
            found = false;
            break;
        }
    }
    for(int i = 0; i < n; i ++){
        if(dist(i, n - 1) <= d){
            found = false;
            break;
        }
    }
    if(found) {
        cout << n + m - 2 << nline;
        return;
    }
    found = true;
    for(int i = 0; i < n; i ++){
        if(dist(i, 0) <= d){
            found = false;
            break;
        }
    }
    for(int i = 0; i < m; i ++){
        if(dist(n - 1, i) <= d){
            found = false;
            break;
        }
    }
    if(!found) cout << -1 << nline;
    else cout << n + m - 2<< nline;
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}