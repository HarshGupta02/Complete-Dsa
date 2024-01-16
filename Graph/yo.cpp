#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline endl
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll nax = 4e5 + 5;

void solve(){
    ll n;
    cin >> n;
    vector<bool>visited(nax,false);
    vector<ll>v1;
    vector<ll>v2;
    map<ll,ll>mp1,mp2;
    for(int i = 0; i < n ; i ++){
        ll a , b;
        cin >> a >> b;
        if(visited[a] == false and visited[b] == false){
            v1.push_back(a); v1.push_back(b);
            visited[a] = true; visited[b] = true;
            mp1[a] ++; mp1[b] ++;
        }else{
            v2.push_back(a); v2.push_back(b);
            mp2[a] ++; mp2[b] ++;
        }
    }
    bool can = true;
    for(auto it : mp1){
        if(it.second > 1){
            can = false; break;
        }
    }
    for(auto it : mp2){
        if(it.second > 1){
            can = false; break;
        }
    }
    if(!can) cout << "NO" << nline;
    else cout << "YES" << nline;
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