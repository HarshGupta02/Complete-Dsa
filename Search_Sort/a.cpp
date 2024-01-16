#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n;
	cin >> n;
	ll cnt = 0;
	while(n % 2 == 0){
	    n /= 2;
	    cnt ++;
	}
	if(cnt % 2 == 1){
	    n *= 2;
	    cnt --;
	}
	ll even = (ll)1 << (cnt/2);
	ll a = -1, b = -1;
	for(int i = 0; i * i <= n; i ++){
	    // i  is basically A.
	    ll x = n - (i * i);
	    ll y = sqrtl(x);
	    if(y * y != x) y ++;
	    if(y * y != x) continue;
	    a = i; b = y;
	}
	if(a == -1) cout << -1 << nline;
	else{
	    cout << even * a << " " << even * b << nline;
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