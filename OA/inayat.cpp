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
    vector<int> rank(n);
    for(int i = 0; i < n; i ++) cin >> rank[i];
    int n = rank.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        int sum = 0;
        for(int j = i; j < n; j ++) {
            sum += rank[j];
            int len = (j - i + 1);
            if((sum % len) != 0) continue;
            mp[sum/len] ++;
        }
    }
    vector<int> ans(n);
    for(int x = 1; x <= n; x ++) {
        ans[x - 1] = mp[x];
    }
    return ans;
    for(auto it : ans) cout << it << " ";
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