#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// map<string,int>mp;
unordered_map<string,int>mp;

void f(string s , string& temp , int i , int n){  //// T(N) = 2 * T(N-1) ==== 2^N
    if(i == n){
        if(mp[temp] != 1){
            mp[temp] = 1;
            cout << temp << " ";
        }
        return;
    }
    temp.push_back(s[i]);
    f(s,temp,i + 1,n);
    temp.pop_back();
    f(s,temp,i + 1,n);
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    string temp = "";
    f(s,temp,0,n);
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