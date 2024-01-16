#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;

ll fast_exp(ll a ,ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res % MOD;
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp1(n, vector<ll> (m, 0));
    vector<vector<ll>> dp2(n, vector<ll> (m, 0));
    ll free_cells = 0;
    dp1[n - 1][m - 1] = 1;
    for(int i = n - 1; i >= 0; i --) {
        for(int j = m - 1; j >= 0; j --) {
            if(grid[i][j] == '#') dp1[i][j] = 0;
            else {
                free_cells ++;
                if(i + 1 < n) 
                    dp1[i][j] = (dp1[i][j] + dp1[i + 1][j]) % MOD;
                if(j + 1 < m) 
                    dp1[i][j] = (dp1[i][j] + dp1[i][j + 1]) % MOD;
            }
        }
    }
    dp2[0][0] = 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(grid[i][j] == '#') dp2[i][j] = 0;
            else {
                if(i - 1 >= 0) 
                    dp2[i][j] = (dp2[i][j] + dp2[i - 1][j]) % MOD;
                if(j - 1 >= 0) 
                    dp2[i][j] = (dp2[i][j] + dp2[i][j - 1]) % MOD;
            }
        }
    }
    ll needed = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            ll a = dp1[i][j], b = dp2[i][j];
            ll c = (a*b) % MOD;
            if(c == dp1[0][0] and dp1[0][0] != 0) needed ++;
        }
    }
    ll x = fast_exp(free_cells, MOD - 2);
    ll y = (needed * x) % MOD;
    cout << y << endl;
    return 0;
}

