#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// s[i] = 0 -> prev = 0
// s[i] = 1 -> prev = 1

int go(int i, int prev, int n, string &s, vector<vector<int>> &dp) {
    if(i >= n) return 0;
    if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
    int ans = INT_MAX;
    if(s[i] == '?') {
        if(i == 0) {
            ans = min(ans, go(i + 1, 0, n, s, dp));
            ans = min(ans, go(i + 1, 1, n, s, dp));
        }else if(prev == 0) {
            ans = min(ans, go(i + 1, 0, n, s, dp));
            ans = min(ans, 1 + go(i + 1, 1, n, s, dp));
        }else {
            ans = min(ans, 1 + go(i + 1, 0, n, s, dp));
            ans = min(ans, go(i + 1, 1, n, s, dp));
        }

    }else {
        if(i == 0 and s[i] == '0') ans = min(ans, go(i + 1, 0, n, s, dp));
        else if(i == 0 and s[i] == '1') ans = min(ans, go(i + 1, 1, n, s, dp));
        else if((s[i] - '0') == prev) {
            if(s[i] == '0') ans = min(ans, go(i + 1, 0, n, s, dp));
            else ans = min(ans, go(i + 1, 1, n, s, dp));
        }else {
            if(s[i] == '0') ans = min(ans, 1 + go(i + 1, 0, n, s, dp));
            else ans = min(ans, 1 + go(i + 1, 1, n, s, dp));
        }
    }
    return dp[i][prev + 1] = ans;
}

void solve(){
    string s;
    cin >> s;
    int n = serverType.size();
    vector<vector<int>> dp(n + 1, vector<int> (3, -1));
    // return go(0, -1, n, serverType, dp);
    cout << go(0, -1, n, serverType, dp) << "\n";
}

int main() {
    fast_cin();
    ll test_cases = 1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}