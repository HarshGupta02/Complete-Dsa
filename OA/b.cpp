#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll digit_sum(ll num) {
    ll sum = 0;
    while(num > 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

void solve(){
    ll n;
    cin >> n;
    map<int, int> mp1, mp2;
    for(int i = 1; i <= n; i ++) mp1[digit_sum(i)] ++;
    for(auto it : mp1) mp2[(-1 * it.second)] ++;
    return mp2.begin() -> second;
    cout << mp2.begin() -> second << endl;
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