#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n = palindromeStr.size();
    int cnt = 0;
    for(auto ch : palindromeStr) {
        if(ch == 'a') cnt ++;
    }
    if(cnt == n) return "IMPOSSIBLE";
    for (int i = 0; i < n / 2; ++i) {
        if (palindromeStr[i] != 'a') {
            palindromeStr[i] = 'a';
            return palindromeStr;
        }
    }
    palindromeStr[n - 1] = 'b';
    return n < 2 ? "IMPOSSIBLE" : palindromeStr;
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