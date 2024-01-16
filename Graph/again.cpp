#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    deque<char>dq;
    int i = 0, j = n - 1;
    int chance = 0; // 0 = alice;
    while(i <= j){
        if(chance == 0){
            char ch = s[i];
            if(dq.empty()) dq.push_front(ch);
            else {
                char tp = dq.front();
                if(ch > tp) dq.push_back(ch);
                else if(ch < tp) dq.push_front(ch);
                else{
                    int k = 0;
                }
            }
            chance = 1 - chance;
        }else{
            char ch = s[i];
            if(dq.empty()) dq.push_front(ch);
            else {
                char tp = dq.front();
                if(ch >= tp) dq.push_front(ch);
                else dq.push_back(ch);
            }
            chance = 1 - chance;
        }
    }
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