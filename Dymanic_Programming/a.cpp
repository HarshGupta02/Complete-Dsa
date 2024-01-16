#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

/*
observations =>

1. in each operation try to take the longest balanced subarray.
2. we find the number of 1's and 0's and consider the one which is smaller in freq.
3. we consider the string with left = first occ of min char and right = last 
occ of min char.
4. and then we expand in either side until cnt of larger = cnt of smaller.
5. we always try to replace the balanced subarray with that bit that corresponds
to forming a balanced array again. 

*/

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll one_cnt = 0, zero_cnt = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == '1') one_cnt ++;
        else zero_cnt ++;
    }
    ll left = 0, right = n - 1;
    if(one_cnt >= zero_cnt){
        while(left < n and s[left] == '1') left ++;
        while(right >= 0 and s[right] == '1') right --;
        
    }else{

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