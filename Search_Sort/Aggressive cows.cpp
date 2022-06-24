////  TIME = O(LOG X * C * LOG N) ~ O(27 * 10 ^ 5 * 16)



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll n ,c;
vector<ll>x;
ll ans;

bool Valid(ll mid){
    ll prev_pos = x.front();
    ll last_pos = x.back();
    ll cows_placed = 1;
    while(cows_placed != c){
        ll pos_to_find = prev_pos + mid;
        auto it = lower_bound(x.begin() , x.end() , pos_to_find);
        if(it != x.end()){
            ll idx = it - x.begin();
            prev_pos = x[idx]; cows_placed ++;
        }else return false;
    }
    return true;
}

void Binary_Search(){
    ll low = 1 , high = x.back() - x.front();
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(Valid(mid)){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
}

void solve(){
    cin >> n >> c;
    x.resize(n);
    for(int i = 0 ; i < n ; i ++) cin >> x[i];
    sort(all(x));
    Binary_Search();
    cout << ans << nline;
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
        x.clear();
    }
    return 0;
}