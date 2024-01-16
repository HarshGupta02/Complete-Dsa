#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// 1 2 3 3 4 5
// 1 2 3 4
// 5 3 5 7 8

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        bool found = true;
        for(int j = i + 1; j < i + k; j ++) {
            if(a[j] > a[j - 1]) continue;
            found = false;
            break;
        }
        if(found) 
    }
    cout << cnt << endl;
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