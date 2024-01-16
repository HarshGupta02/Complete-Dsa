#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string st = "";
    st.push_back('@');
    for(int i = 0; i < n; i ++){
        st.push_back('#');
        st.push_back(s[i]);
    }
    st.push_back('#'); st.push_back('$');
    vector<int>lps(st.size(), 0);
    int center = 0, right = 0;
    for(int i = 1; i < st.size() - 1; i ++){
        int mirror = center - (i - center);
        if(i < right) lps[i] = min(lps[mirror], right - i);
        while(st[i + 1 + lps[i]] == st[i - 1 - lps[i]]) lps[i] ++;
        if(i + lps[i] > right){
            center = i;
            right = i + lps[i];
        }
    }
    int best_len = 0, best_idx;
    for(int i = 0; i < st.size(); i ++){
        if(lps[i] > best_len){
            best_len = lps[i];
            best_idx = i;
        }
    }
    if(st[best_idx] != '#'){
        int start = ((best_len - best_idx) + (best_len % 2))/2 - 1;
        return s.substr(start, (best_len % 2) ? best_len : best_len + 1);
    }
    int start = ((best_len - best_idx) + !(best_len % 2))/2 - 1;
    return s.substr(start , !(best_len % 2) ? best_len : best_len + 1);
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