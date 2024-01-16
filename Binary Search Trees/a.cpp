#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    map<ll, ll>mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] = 1;
    }
    ll maxi = *max_element(a.begin(), a.end());
    if(k == 1){
        for(ll i = 1; i <= 2 * n; i ++){
            if(mp[i] != 1){
                cout << maxi - min(maxi, i) << nline;
                return;
            }
        }
        return;
    }
    ll ans = 0;
    if(maxi != (2 * n)){
        maxi = 2 * n;
        k --; mp[2 * n] = 1;
    }
    for(int i = 1; i <= 2 * n; i ++){
        if(k == 0) break;
        if(mp[i] == 1) continue;
        ans += (maxi - i); k --;
    }
    cout << ans << nline;
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