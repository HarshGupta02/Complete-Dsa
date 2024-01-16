#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(int test_case){
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    vector<ll>s1, s2;
    string ans = "YES";
    for(int i = 0; i < n; i ++) cin >> a[i];
    if(n > (2 * k)) ans = "NO";
    else{
        for(int i = 0; i < n; i ++){
            ll x = a[i];
            if(find(all(s1), x) == s1.end()) s1.push_back(x);
            else if(find(all(s2), x) == s2.end()) s2.push_back(x);
            else {
                ans = "NO"; break;
            }
        }
    }
    cout << "Case #" << test_case << ": " << ans << nline;
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve(it);
    }
    return 0;
}