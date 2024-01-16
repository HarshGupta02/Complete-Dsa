#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MAXN = 1e6 + 5;

bool unq_digits(int num) {
    int cnt = 0;
    set<int> st;
    while(num > 0) {
        st.insert(num % 10);
        cnt ++;
        num /= 10;
    }
    return (st.size() == cnt);
}

void solve(){
    vector<int> dp(MAXN + 1, 0);
    for(int i = 1; i <= MAXN; i ++) {
        dp[i] = dp[i - 1] + (unq_digits(i) == true ? 1 : 0);
    }
    // vector<vector<int>> arr = {{7,8}, {52, 80}, {34, 84}, {57, 64}, {74, 78}};
    int n = arr.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i ++) {
        int x = arr[i][0], y = arr[i][1];
        cout << dp[y] - dp[x - 1] << endl;
    }
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