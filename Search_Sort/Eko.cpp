#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll n , m;
vector<ll>h;

bool helper(ll mid){
    ll cut_off = 0;
    for(int i = 0 ; i < n ;i ++){
        cut_off += max(0 * 1ll , h[i] - mid);
    }
    if(cut_off >= m) return true;
    return false;
}

void solve(){
    cin >> n >> m;
    h.resize(n);
    for(int i = 0; i < n ; i ++) cin >> h[i];
    ll low = 1 , high = 1e18;
    ll ans;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(helper(mid)){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
    cout << ans << nline;
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