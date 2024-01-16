#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// 0000100 10001 011111

// 1.0001011 01010 100000

// 2.0010100 10101 010000

// 3.0101011 01010 101000

// 4.1010100 10101 010100

// 5.0101011 01010 101010

// 6.1010100 10101 010101

// 7.0101011 01010 101010

// 8.1010100 10101 010101

// 100110 101 11 000

// 1. 011001 010 00 100
// 2. 100110 101 01 010
// 3. 011001 010 10 101
// 4. 100110 101 01 010

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll>a;
    for(int i = 0; i < n; i ++){
        if(s[i] == '1') a.push_back(i);
    }
    string ans(n, '0');
    ll sz = a.size();
    // 14 3
    // 10011010111000
    for(int i = 0; i < sz; i ++){
        if(i + 1 < sz){
            ll diff = a[i + 1] - a[i] - 1; // number of zeros between two ones.
            // cout << diff << nline;
            if(k <= (diff/2)){
                int p = a[i], q = a[i + 1];
                ll temp = k;
                while(temp > 0){
                    p ++; q --; temp --;
                }
                ans[p] = '1'; ans[q] = '1';
                p = a[i], q = a[i + 1];
                char ch;
                if(k % 2 == 0) ch = '1';
                else ch = '0';
                temp = k - 1;
                while(temp > 0){
                    ans[p] = ch; ans[q] = ch;
                    p ++; q --; temp --;
                    if(ch == '1') ch = '0';
                    else ch = '1';
                }
            }else{
                int p = a[i], q = a[i + 1];
                int temp = diff/2;
                while(temp > 0){
                    p ++; q --; temp --;
                }
                ans[p] = '1'; ans[q] = '1';
                // cout << ans << nline;
                // return;
                p = a[i], q = a[i + 1];
                char ch;
                if((diff/2) % 2 == 1) ch = '0';
                else ch = '1';
                // cout << ch << nline;
                // return;
                // 10011010111000
                temp = (diff/2) - 1;
                ans[p] = ch; ans[q] = ch;
                while(temp > 0){
                    ans[p] = ch; ans[q] = ch;
                    p ++; q --; temp --;
                    if(ch == '1') ch = '0';
                    else ch = '1';
                }
                // cout << ans << nline;
                ll r = diff/2;
                if(r % 2 == 1){
                    if(k % 2 == 1) continue;
                    else{
                        for(int i = 0; i < n; i ++){
                            if(ans[i] == '1') ans[i] = '0';
                            else ans[i] = '1';
                        }
                    }
                }else{
                    if(k % 2 == 0) continue;
                    else{
                        for(int m = a[i]; m <= a[i + 1]; m ++){
                            if(ans[m] == '1') ans[m] = '0';
                            else ans[m] = '1';
                        }
                    }
                }
            }
        }
    }
    cout << ans << nline;
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