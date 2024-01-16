#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

void solve(){
    int h, w, ax, ay, bx, by;
    cin >> h >> w >> ax >> ay >> bx >> by;
    if(ax >= bx) {
        cout << "Draw\n";
        return;
    }
    // let's say both come to one column(same y)
    // if gap btw them is even so (opp chance) one wins
    // if gap btw them is odd so (chance) one wins
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}