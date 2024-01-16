#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline endl
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n, l , r;
    cin >> n >> l >> r;
    if(n == 1){
        cout << "YES" << nline;
        cout << l << nline;
        return;
    }
    bool found = true;
    vector<ll>ans;
    for(ll i = 1; i <= n ; i ++){
        ll nxt = l + (i - (l % i));
        if(nxt >= l and nxt <= r) ans.push_back(nxt);
        else{
            found = false; break;
        }
    }
    if(!found){
        cout << "NO" << nline; return;
    }
    // else{
    //     cout << "YES" << nline;
    //     // for(auto it : ans) cout << it << " ";
    //     // cout << nline;
    // }
    set<ll>st;
    for(ll i = 0 ; i < ans.size(); i ++){
        ll x = __gcd(i + 1, ans[i]);
        st.insert(x);
    }
    if(st.size() == n){
        cout << "correct" << nline;
    }else{
        cout << "incorrect" << nline;
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