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
    string s1,s2,res;
    cin >> s1 >> s2 >> res;
    int n1 = s1.size() , n2 = s2.size() , n3 = res.size();
    bool possible = true;
    if(n1 + n2 != n3){
        cout << "not possible" << endl;
        return;
    }
    int i = 0, j = 0, k = 0;
    while(k < n3){
        if(i < n1 and s1[i] == res[k]){
            i ++; k ++; continue;
        }
        if(j < n2 and s2[j] == res[k]){
            j ++; k ++; continue;
        }
        possible = false;
        return;
    }
    if(possible) cout << "possible" << endl;
    else cout << "not possible" << endl;
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