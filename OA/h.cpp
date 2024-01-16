#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll CountBitSetsFast(ll n){
    ll count=0;
    while(n > 0){
        n = n & (n-1); 
        count ++;
    }
    return count;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    using ll = long long int;
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<pair<ll,ll>> combine;
    for(int i = 0; i < n; i ++) {
        ll m = CountBitSetsFast(a[i]);
        combine.push_back({m, a[i]});
    }
    sort(combine.begin(), combine.end());
    vector<ll> res;
    for(int i = 0; i < n; i ++) res.push_back(combine[i].second);
    return ans;
    for(auto it : res) cout << it << " ";
    cout << endl;
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