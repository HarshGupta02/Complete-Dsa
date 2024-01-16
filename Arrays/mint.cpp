#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
static const int MOD = 1e9 + 7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


template<ll MOD = 1000000007>
struct mint{
    ll x;
    ll mod = MOD;
    mint(ll x=0):x(x%MOD){}
    mint& operator+=(const mint a){
        if((x+=a.x)>=MOD) x-=MOD;
        return *this;
    }
    mint& operator-=(const mint a){
        if((x += MOD-a.x)>=MOD) x-=MOD;
        return *this;
    }
    mint& operator*=(const mint a){
        (x*=a.x)%=MOD;
        return *this;
    }
    mint operator+(const mint a) const{
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const{
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const{
        mint res(*this);
        return res*=a;
    }
    mint power(ll t) const{
        if(!t) return 1;
        mint a = power(t>>1);
        a*=a;
        if(t&1) a*=*this;
        return a;
    }

    mint inv() const{
        return power(MOD-2);
    }
    mint& operator/=(const mint a){
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const{
        mint res(*this);
        return res/=a;
    }
};
// using mll = mint<>;

void solve(){
    mint<MOD> mll, ans;
    ans += 5;
    cout << ans << endl;
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