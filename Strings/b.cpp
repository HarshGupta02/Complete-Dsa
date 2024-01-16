#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int f(ll x){
    int cnt = 0;
    while(x > 0){
        cnt ++;
        x/=10;
    }
    return cnt;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n), b(n);
    map<ll,ll>mp1, mp2, mp3;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mp1[a[i]] ++;
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        mp2[b[i]] ++;
    }
    vector<priority_queue<ll, vector<ll>, greater<ll>>>af(11), bf(11);
    for(int i = 0; i < n; i ++){
        if(mp2[a[i]] > 0){
            mp3[a[i]] ++;
        }
    }
    for(int i = 0; i < n; i ++){
        if(mp3[b[i]] > 0){
            mp3[b[i]] --; continue;
        }
        int d1 = f(a[i]), d2 = f(b[i]);
        af[d1].push(a[i]); bf[d2].push(b[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i ++){
        if(mp2[a[i]] > 0){
            mp2[a[i]] --; continue;
        }
        int d = f(a[i]);
        if(d > 1){
            if(bf[d].size() > 0){
                bf[d].pop(); ans += 2; continue;
            }
            if(bf[1].size() > 0 and bf[1].top() == 1){
                bf[1].pop(); ans += 2; continue;
            }
            if(bf[1].size() > 0 and bf[1].top() != 1){
                bf[1].pop(); ans += 3; continue;
            }
            ans += 4;
        }else{
            if(bf[a[i]].size() > 0){
                bf[a[i]].pop(); ans += 1; continue;
            }
            if(bf[d].size() > 0){
                bf[d].pop(); ans += 2; continue;
            }
            if(bf[1].size() > 0 and bf[1].top() == 1){
                bf[1].pop(); ans += 2; continue;
            }
            if(bf[1].size() > 0 and bf[1].top() != 1){
                bf[1].pop(); ans += 3; continue;
            }
            ans += 4;
        }
    }
    cout << ans << nline;
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