#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i]; a[i] --;
        mp[a[i]] = -1;
    }
    ll i = 0, j = 0, ans = 0;
    while(i < n and j < n){
        if(mp[a[j]] == -1) mp[a[j]] = j;
        else {
            if(mp[a[j]] >= i) i = mp[a[j]] + 1;
            mp[a[j]] = j;
        }
        ans = max(ans, j - i + 1);
        j ++;
    }
    cout << ans << "\n";
    return 0;
}