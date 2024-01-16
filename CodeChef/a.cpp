#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int go(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1;
    if(n % 2 == 0) {
        int cnt = n, ans = 0;
        while(cnt > 0) {
            ans += abs(a[l1 ++] - b[r2 --]);
            cnt --;
            if(cnt > 0) {
                ans += abs(a[r1 --] - b[l2 ++]);
                cnt --;
            }else break;
        }
        return ans;
    }
    int cnt = n - 1, ans = 0;
    while(cnt > 0) {
        ans += abs(a[l1 ++] - b[r2 --]);
        cnt --;
        if(cnt > 0) {
            ans += abs(a[r1 --] - b[l2 ++]);
            cnt --;
        }else break;
    }
    int left = abs(a[l1] - b[l2]);
    int right = abs(a[l1] - b[r2]);
    return (ans + max(left, right));
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = go(a, b);
    vector<int> c;
    for(int i = 0; i < n; i ++) c.push_back(b[i]);
    ans = max(ans, go(a, c));
    c.clear();
    for(int i = m - n; i < m; i ++) c.push_back(b[i]);
    ans = max(ans, go(a, c));
    cout << ans << "\n";
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