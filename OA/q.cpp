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
    vector<string> text(n);
    for(int i = 0; i < n; i ++) cin >> text[i];
    int n = text.size();
    map<string, int> mp;
    set<string> st;
    vector<string> ans;
    for(int i = 0; i < n; i ++) {
        string curr = text[i];
        string temp = curr;
        sort(temp.begin(), temp.end());
        if(mp[temp] == 0) {
            mp[temp] ++;
            st.insert(curr);
        }
    }
    for(auto it : st) ans.push_back(it);
    return ans;
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