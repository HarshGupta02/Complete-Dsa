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
    ll m , n;
    cin >> m >> n;
    m --; n --;
    vector<ll>v(m) , h(n);
    for(int i = 0 ; i < m; i ++) cin >> v[i];
    for(int i = 0 ; i < n; i ++) cin >> h[i];
    sort(v.rbegin(),v.rend()); sort(h.rbegin() , h.rend());
    ll ans = 0;
    ll v_p = 1 , h_p = 1;
    int i = 0 , j = 0;
    while(i < m and j < n){
        if(v[i] >= h[j]){
            ans += v[i] * h_p;
            v_p ++; i ++; continue;
        }
        ans += h[j] * v_p;
        h_p ++; j ++;
    }
    while(i < m){
        ans += v[i] * h_p; v_p ++; i ++;
    }
    while(j < n){
        ans += h[j] * v_p; h_p ++; j ++;
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