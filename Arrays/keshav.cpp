#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<ll> nextLargerElementRight(vector<ll> arr, int n){
    stack<ll>stk;
    vector<ll>ans(n, -1);
    for(int i = 0 ; i < n ; i ++){
        if(stk.empty() or arr[i] <= arr[stk.top()]) stk.push(i);
        else {
            while(!stk.empty() and arr[i] > arr[stk.top()]) {
                ans[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    return ans;
}

vector<ll> nextLargerElementLeft(vector<ll> arr, int n){
    stack<ll>stk;
    vector<ll>ans(n, -1);
    for(int i = n - 1; i >= 0; i --) {
        if(stk.empty() or arr[i] <= arr[stk.top()]) stk.push(i);
        else {
            while(!stk.empty() and arr[i] > arr[stk.top()]) {
                ans[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> nger = nextLargerElementRight(a, n);
    vector<ll> ngel = nextLargerElementLeft(a, n);
    for(int i = 0; i < n; i ++) {
        if(nger[i] == -1) nger[i] = n - 1;
        else nger[i] --;
    }
    for(int i = 0; i < n; i ++) {
        if(ngel[i] == -1) ngel[i] = 0;
        else ngel[i] ++;
    }
    for(auto it : nger) cout << it << " ";
    cout << endl;
    for(auto it : ngel) cout << it << " ";
    cout << endl;
    ll sum = 0;
    for(int i = 0; i < n; i ++) {
        ll cnt = 1;
        int left_idx = ngel[i], right_idx = nger[i];
        ll curr = 0;
        cnt *= ((i - left_idx) + 1);
        cnt *= ((right_idx - i) + 1);
        sum += a[i] * cnt;
    }
    cout << endl;
    cout << sum << endl;
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