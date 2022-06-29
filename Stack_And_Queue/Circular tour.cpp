#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    vector<ll>p(n),d(n);
    for(int i =0 ; i < n ; i++) cin >> p[i];
    for(int i =0 ; i < n ; i ++) cin >> d[i];
    vector<pair<ll,ll>>v;
    for(int i =0 ;i < n ; i ++) v.push_back({p[i] , d[i]});
    int start = 0 , extra_fuel = 0 , req_fuel = 0;
    for(int i = 0; i < n ; i++){
        extra_fuel = (extra_fuel + v[i].first) - v[i].second;
        if(extra_fuel < 0){
            start = i + 1;
            req_fuel += extra_fuel;
            extra_fuel = 0;
        }
    }
    if(extra_fuel + req_fuel >= 0) cout << start << nline;
    else cout << -1 << nline;
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