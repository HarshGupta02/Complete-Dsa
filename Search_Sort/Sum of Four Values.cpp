/*
TIME = O(N^2* LOGN) = WITHOUT CUSTOM HASH MAP
TIME = O(N^2) = WITH CUSTOM HASH MAP

here for each i, we see that if any j exists < i such that map contains this
sum of x - a[i] - a[j]. if not so we iterate for all j's > i and add unique
sum of a[i] + a[j] to a map of int, pair.

*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long int;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

struct chash {
	const uint64_t C = ll(2e18*acos((long double)-1))+71;
	const int RANDOM = rng();
	ll operator()(ll x) const { 
		return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using ht = gp_hash_table<K,V,chash>;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    ht<ll, pair<ll,ll>> mp;
    for(int i = n - 1; i >= 0; i --){
        for(int j = i - 1; j >= 0; j --){
            ll to_find = x - a[i] - a[j];
            if(mp.find(to_find) != mp.end()){
                cout << i + 1 << " " << j + 1 << " " << mp[to_find].first + 1 << " " << mp[to_find].second + 1;
                return 0;
            }
        }
        for(int j = i + 1; j < n; j ++) mp[a[i] + a[j]] = {i, j};
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}