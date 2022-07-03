///  METHOD 1: WE USED THE FACT THAT IF WE SEE ITH ELEMENT AND WE WANT TO DEARRANGE IT
/// SO WE HAVE I - 1 POSITIONS FOR IT. IF WE SELECT A POSITION AND THE ELEMENT ALREADY
/// AT THAT POSITION COMES TO I'TH ELEMENT PLACE SO WE HAVE I - 2 NUMBERS TO BE DEARR
/// ANGED AND IF THAT ELEMENT DOES NOT COME TO THE ITH PLACE THEN THERE ARE I - 1 PLACES
/// WHERE HE CAN GO. 

/// SO TOTAL WAYS ARE DP[I] = (I - 1) * DP[I - 2] + (I - 1) * DP[I - 1];

/// TIME = O(N) , SPACE = O(N).


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
    vector<int>dp(n + 1);
    dp[1] = 0; dp[2] = 1;
    for(int i = 3; i <= n ; i ++){
        dp[i] = (((i - 1) * dp[i - 2]) % MOD + ((i - 1) * dp[i - 1]) % MOD) % MOD;
    }
    return dp[n] % MOD;
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

/// METHOD 2: TIME = O(N) , SPACE = O(1);


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
    ll prev_2, prev_1 , curr;
    prev_2 = 0 , prev_1 = 1;
    for(ll i = 3; i <= n ; i ++){
        curr = (((i - 1) * prev_2) % MOD + ((i - 1) * prev_1) % MOD) % MOD;
        prev_2 = prev_1;
        prev_1 = curr;
    }
    cout << prev_1 % MOD << nline;
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

/// METHOD 3 : 

// D(N) = N! (1 - 1/1! + 1/2! - 1/3! + 1/4! - 1/5! .. + (-1)^N . 1/N!);