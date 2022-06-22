//// TIME = O(MIN(LOG N , LOG M )) , SPACE = O(1).

/*

HERE WE DECIDE , WHERE THE PARTITION SHOULD BE PLACED SO THAT THE LEFT PART CHOSEN
OF BOTH THE ARRAYS FORM THE LEFT PART OF THE ORIGINAL ARRRAY AND OTHER ELEMENTS
FORM THE RIGHT HALF OF THE ORIGINAL ARRAY.

WE APPLY BINARY SEARCH ON NUMBER OF ELEMENTS TO CHOOSE FOR THE LEFT ARRAY FROM 
ARRAY1 AND IF IT IS NOT VALID THEN WE ARE SURE THAT WE CANNOT A PLACE A PARTITION 
AFTER THAT SO WE DO HIGH = CUT1 - 1 ELSE IF VALID , WE TRY TO GO RIGHT TOWARS THE 
CENTER AND SO WE DO LOW = CUT1 + 1;

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

void solve(){
    int n , m;
    cin >> n >> m ;
    vector<int>a(n) , b(m);
    for(int i = 0; i < n ; i ++) cin >> a[i];
    for(int i = 0; i < m ; i ++) cin >> b[i];
    /// assuming n < m
    int low = 0 , high = n;
    while(low <= high){
        int cut1 = low + (high - low) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == m) ? INT_MAX : b[cut2];
        if(l1 <= r2 and l2 <= r1){
            if((n + m) % 2 == 0){
                cout << (double)(max(l1 , l2) + min(r1 , r2))/2 << endl;
                break;
            }
            cout << (double)(max(l1 , l2)) << endl;
            break;
        }else if(l1 > r2){
            high = cut1 - 1;
        }else{
            low = cut1 + 1;
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