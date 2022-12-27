/// METHOD 1: TIME = O(N ^ 2) , SPACE = O(1).


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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    int i = 0, j = 0;
    while(i < n and j < n){
        if((a[i] >= 0 and a[j] >= 0) or (a[i] <= 0 and a[j] <= 0)){
            j ++; continue;
        }
        while(j != i + 1){
            swap(a[j - 1] , a[j]);
            j -- ;
        }
        i ++; j ++;
    }
    for(auto it : a) cout << it << " ";
    cout << endl;
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