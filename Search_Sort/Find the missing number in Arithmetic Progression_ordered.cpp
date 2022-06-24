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
    vector<ll>a(n);
    for(int i = 0 ;i < n ; i ++) cin >> a[i];
    ll d = ((a.back() - a.front()) / n);
    ll low = 0 , high = n - 1;
    while(high - low > 1){
        ll mid = low + (high - low)/2;
        /// check if left half is AP or not.
        if(((a[mid] - a[low]) / (mid - low)) == d) low = mid;
        else high = mid;
    }
    cout << (a[low] + a[high]) / 2 << endl;
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




// 2,4,8,10,12,14

// 1,6,11,16,21,31

// 0,1,2,3,4, 5, 6
// 2,4,6,8,10,12,14
// a , a+d , a+2d , a+3d , a+4d , a+5d , a+6d

// in ideal AP , (last - first)/ (n - 1) = d 

// in wrong AP , possible d = 14 - 2 / 5  = 12/5 = 2
// this d can be 2 but not sure.

