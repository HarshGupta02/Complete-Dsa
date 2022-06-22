#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n , k;
    cin >> n >> k;
    vector<int>a(n);
    unordered_map<int,int>mp;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i]; mp[a[i]] ++;
    }
    vector<int>ans;
    for(auto it : mp) if(it.second > (n / k)) ans.push_back(it.first);
    for(auto it : ans) cout << it << " "; cout << endl;
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