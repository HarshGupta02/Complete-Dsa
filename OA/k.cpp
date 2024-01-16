#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    map<int, int> mp;
    for(auto it : ids) mp[it] ++;
    vector<pair<int, int>> v;
    for(auto it : mp) v.push_back({it.second, it.first});
    sort(v.begin(), v.end());
    int sz = v.size();
    int ans = 0;
    for(int i = 0; i < sz; i ++) {
        int curr = v[i].first;
        if(curr <= m) m -= curr;
        else {
            ans = sz - i;
            break;
        }
    }
    return ans;
    cout << ans << endl;
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