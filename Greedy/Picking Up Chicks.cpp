/*
here we see from the last because the chicks in front of a chick will decide 
whether the given chick can reach the barn or not. here we also assume that 
all the chicks use the same time to move and not wait for each other.

if one chick cannot reach . then the chicks behind it also can never reach the 
barn.

just see what max distance the chick can reach and what is the actual distance 
btw the chick and the barn . if the former >= latter , then it can reach the 
barn otherwise not.

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll it){
    ll n , k , b , t;
    cin >> n >> k >> b >> t;
    vector<ll>x(n), v(n);
    for(ll i = 0 ; i < n ; i ++) cin >> x[i];
    for(ll i = 0 ; i < n ; i ++) cin >> v[i];
    ll obstacles = 0;
    ll swaps = 0 , cnt = 0;
    for(ll i = n - 1; i >= 0 ; i--){
        ll dist_to_cover = b - x[i];
        ll dist_it_can_cover = v[i] * t;
        if(dist_it_can_cover < dist_to_cover){
            obstacles ++; continue;
        }
        if(obstacles > 0)
            swaps += obstacles;
        cnt ++;
        if(cnt >= k) break; /// ??? why needed
    }
    if(cnt >= k)
        cout << "Case #" << it << ": " << swaps << nline;
    else
        cout << "Case #" << it << ": " << "IMPOSSIBLE" << nline;

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