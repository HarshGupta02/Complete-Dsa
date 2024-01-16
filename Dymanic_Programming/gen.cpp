#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void f(int i, int n, ll &cnt, string s){
    if(i == n){
        for(int i = 0; i <= n - 3; i ++){
            if(s[i] == 'L' and s[i + 1] == 'L' and s[i + 2] == 'L') return;
        }
        cnt ++;
        // cout << s << endl;
        return;
    }
    s.push_back('L');
    f(i + 1, n, cnt, s);
    s.pop_back();
    s.push_back('P');
    f(i + 1, n, cnt, s);
    s.pop_back();
}

void solve(){
    ll n;
    cin >> n;
    ll cnt = 0;
    string s = "";
    f(0, n, cnt, s);
    cout << cnt << endl;  
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