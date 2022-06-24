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
    ll n;
    cin >> n;
    vector<ll>p(n);
    for(int i = 0; i < n ; i ++) cin >> p[i];
    sort(all(p));
    vector<ll>prefix_sum(n); prefix_sum[0] = p.front();
    for(int i = 1; i < n ; i ++) prefix_sum[i] = prefix_sum[i - 1] + p[i];
    ll q;
    cin >> q;
    while(q --){
        ll m ;
        cin >> m;
        if(m < p.front()){
            cout << 0 << " " << 0 << nline;
            continue;
        }
        if(m >= p.back()){
            cout << n << " " << prefix_sum[n - 1] << nline;
            continue;
        }
        auto it = upper_bound(p.begin() , p.end() , m);
        int idx;
        if(it != p.end()){
            it --;
            idx = it - p.begin();
            cout << idx + 1 << " " << prefix_sum[idx] << nline; 
        }
    }
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