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
    vector<ll>a(n);
    for(int i = 0; i < n; i ++) a[i] = i + 1;
    do{

        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n ;i ++){
            if(i % 2 == 0) sum1 ^= a[i];
            else sum2 ^= a[i];
        }
        
        if(sum1 == sum2){
            for(auto it : a) cout << it << " ";
            cout << endl;
            break;
        }


    }while(next_permutation(a.begin(), a.end()));
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