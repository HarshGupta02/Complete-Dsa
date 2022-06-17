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
    char s[] = "test string";
    // map<char,int>mp; takes O(N * logN)
    unordered_map<char,int>mp;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        mp[s[i]] ++;
    }
    for(auto it : mp){
        if(it.second > 1){
            cout << it.first << " occurs " << it.second << " times" << endl;
        }
    }
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