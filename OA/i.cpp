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
    // vector<string> s, t, ans;
    // for(int i = 0; i < n; i ++) cin >> s[i];
    // for(int i = 0; i < n; i ++) cin >> t[i];
    // vector<string> s = {"adeaaefabcdef"};
    // vector<string> t = {"aefaffbcdfdff"};
    int n = s.size();
    vector<string> target(n);
    for(int i = 0; i < n; i ++) {
        string x = s[i], y = t[i];
        map<int, int> mp1, mp2;
        for(char ch : x) mp1[ch - 'a'] ++;
        for(char ch : y) mp2[ch - 'a'] ++;
        bool is = true;
        for(int j = 0; j < 26; j ++) {
            if(abs(mp1[j] - mp2[j]) > 3) {
                is = false;
                break;
            }
        }
        target[i] = (is ? "YES" : "NO");
    }
    return target;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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