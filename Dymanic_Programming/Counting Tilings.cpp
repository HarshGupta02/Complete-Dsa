/*
we try to find the number of ways to fill the grid from the ith column to the last
column and hence we call f(1, m); so if we will the ith column in some ways using 
either of the tile so some tiles get filled for the next column and also this
proves that the current column that we are filling, will also have some cells 
already filled from the i - 1th column.

now since n is upto 10 so we can generate all possible masks for each column. a set
bit of mask tells that it is filled or occupied else it tells that the current cell
is empty.

*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const ll MOD = 1e9 + 7;

ll dp[1001][1 << 11];
// dp[i][j] = number of ways to fill the grid from the ith column to the mth column with current mask being j. mask tells us
// that if bit is 1 so that space is filled else the space is empty.

void generate_next_masks(ll current_mask, int i, ll next_mask, ll n, vector<ll> &next_masks){
    if(i == n + 1) {
        next_masks.push_back(next_mask);
        return;
    }
    if((current_mask & (1 << i)) != 0) generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
    if(i != n) {
        if((current_mask & (1 << i)) == 0 and (current_mask & (1 << (i + 1))) == 0) 
            generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);
            // here using vertical tiles , actually fixes 2 of the blocks or grid cells and hence the subsets reduces largely.
    }
    if((current_mask & (1 << i)) == 0) generate_next_masks(current_mask, i + 1, next_mask + (1 << i), n, next_masks);
}

ll f(ll col, ll mask, ll m, ll n){
    if(col == m + 1) {
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[col][mask] != -1) return dp[col][mask];
    vector<ll> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);
    ll ans = 0;
    for(auto it : next_masks) ans = (ans + f(col + 1, it, m, n)) % MOD;
    return dp[col][mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0, m, n) % MOD << "\n";
    // rows are 1 based
    return 0;
}