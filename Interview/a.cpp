// 8
// 8 2 3 1 1 7 4 3

// [8,3,1]
// [2,1,7,4,3]

// 5
// 1 2 3 4 5

// [1,3,4]
// [2,2,5]

#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    if(n == 1) {
        cout << "0\n";
        return;
    }
    vector<int> first,second;
    if(a[0] >= a[1]) {
        first.push_back(a[0]);
        second.push_back(a[1]);
    }else {
        first.push_back(a[1]);
        second.push_back(a[0]);
    }
    int ans = 0;
    for(int i = 2; i < n; i ++) {
        int sz1 = (int)first.size(), sz2 = (int)second.size();
        int last1 = first.back(), last2 = second.back();
        bool can_1 = (last1 >= a[i]) ? true : false;
        bool can_2 = (last2 >= a[i]) ? true : false;
        if(last1 >= last2) {
            if(can_1 == true and can_2 == false) {
                first.push_back(a[i]);
            }else if(can_1 == true and can_2 == true) {
                second.push_back(a[i]);
            }else {
                second.push_back(a[i]);
                ans ++;
            }
        }else {
            if(can_2 == true and can_1 == false) {
                second.push_back(a[i]);
            }else if(can_2 == true and can_1 == true) {
                first.push_back(a[i]);
            }else {
                first.push_back(a[i]);
                ans ++;
            }
        }
    }
    int ans1 = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] < a[i + 1]) ans1 ++;
    }
    cout << min(ans, ans1) << "\n";
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