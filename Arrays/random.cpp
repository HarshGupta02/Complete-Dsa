#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    map<string, string> mp;
    map<string,int> seen;
    for(int i = 0; i < n; i ++){
        string s, t;
        cin >> s >> t;
        mp[s] = t;
    }
    for(auto it : mp){
        string start = it.first;
        string to = it.second;
        if(seen[start] == 1) continue;
        seen[start] = 1;
        while(start != to and mp.find(to) != mp.end() and !seen[to]) {
            seen[to] = 1;
            to = mp[to];
        }
        if(start == to){
            cout << "No" << nline;
            return;
        }
    }
    cout << "Yes" << nline;
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