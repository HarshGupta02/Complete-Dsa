/// METHOD 1 : TIME = O(N) , SPACE = O(N).

/*

HERE WE FIRST FIND OUT THAT IF WE SELL ON ITH DAY OR BEFORE, WHAT IS THE MAX PROFIT
WE CAN GET AND IT IS EQUAL TO DP_L[I] = MAX(ARR[I] - MIN(ARR[0..I - 1])) , DP_L[I - 1]).

AND THEN WE ITERATE FROM BACK AND WE FIND OUT THAT IF WE BUY A STOCK ON THIS DAY OR
IN FUTURE, THEN WHAT IS THE MAX PROFIT WE CAN GET AND IT IS EQUAL TO 
DP_R[I] = MAX(MAX(ARR[I ... N - 1] - ARR[I]) , DP_R[I + 1]);

SO NOW FOR EACH DAY WE HAVE MAX PROFIT OF 2 NON OVERLAPPING TRANSACTIONS IN WHICH SELLING WAS DONE
BEFORE THE I'TH DAY FOR ONE TRANSACTIONS AND BUYING WAS DONE AFTER THE I'TH DAY FOR SECOND TRANSACTION.

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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    vector<int>dp_left(n);
    dp_left[0] = 0;
    int mini = a[0];
    for(int i = 1; i < n ; i ++){
        mini = min(mini , a[i]);
        dp_left[i] = max(dp_left[i - 1] , a[i] - mini);
    }
    vector<int>dp_right(n);
    dp_right[n - 1] = 0;
    int maxi = a[n - 1];
    for(int i = n - 2;  i >= 0 ; i --){
        maxi = max(maxi , a[i]);
        dp_right[i] = max(dp_right[i + 1] , maxi - a[i]);
    }
    int ans = 0;
    for(int  i =0 ; i < n ; i ++){
        ans = max(ans , dp_left[i] + dp_right[i]);
    }
    cout << ans << endl;
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
