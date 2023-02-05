/*
we first of all, we solve for [0,b] and [0, a-1] and then subtract both the ans 
from each other. 
two adjacent numbers cannot be equal to each other except when there are leading 
zeros and 2 leading zeros means nothing and then do not violate the property. 
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;

ll dp[20][10][2][2];

ll f(string &s, int n, int x, bool leadingZeros, bool tight){
    if(n == 0) return 1;
    if(x != -1 and dp[n][x][leadingZeros][tight] != -1)  return dp[n][x][leadingZeros][tight];
    int lb = 0;
    int ub = (tight ? s[s.size() - n] - '0': 9);
    ll ans = 0;
    for(int dig = lb; dig <= ub; dig ++){
        if(dig == x and leadingZeros == false) continue;
        ans += f(s, n - 1, dig, (leadingZeros and dig == 0), (tight & (dig == ub)));
    }
    return dp[n][x][leadingZeros][tight] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    string s1 = to_string(a - 1), s2 = to_string(b);
    int n1 = s1.size(), n2 = s2.size();
    memset(dp, -1, sizeof(dp));
    ll ans1 = f(s2, n2, -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = f(s1, n1, -1, 1, 1);
    cout << ans1 - ans2 << "\n";
    return 0;
}