#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    string s;
    cin >> s;
    int w = 0, b = 0;
    int i = 1, n = s.size();
    int cnt = 1;
    while(i < n) {
        if(colors[i] == colors[i - 1]) cnt ++;
        else {
            if(colors[i - 1] == 'w') w += max(0, cnt - 2);
            else b += max(0, cnt - 2);
            cnt = 1;
        }
        i ++;
    }
    if(s[i - 1] == 'w') w += max(0, cnt - 2);
    else b += max(0, cnt - 2);
    return w > b ? "Wendy" : "Bob";
    // if(w > b) cout << "Wendy" << endl;
    // else cout << "Bob" << endl;
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