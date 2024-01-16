#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    string s = "I like cheese", t = "like";
    unordered_map<string, int> mp;
    vector<string> v, ans;
    stringstream ss(s), tt(t);
    string word1, word2;
    while(ss >> word1) {
        mp[word1] ++;
        v.push_back(word1);
    }
    while(tt >> word2) mp[word2] --;
    for(auto it : v) {
        if(mp[it] > 0) ans.push_back(it);
    }
    return ans;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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