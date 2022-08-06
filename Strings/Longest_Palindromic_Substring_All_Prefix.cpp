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
    for(int k = 1; k <= n; k ++){
        string curr = s.substr(0, k);
        string st = "";
        st.push_back('@');
        for(int i = 0; i < curr.size() ; i ++){
            st.push_back('#');
            st.push_back(curr[i]);
        }
        st.push_back('#'); st.push_back('$');
        int sz = st.size();
        vector<int>lps(sz, 0);
        int center = 0, right = 0;
        for(int i = 1; i < sz - 1; i ++){
            int mirror = center - (i - center);
            if(i < right) lps[i] = min(lps[mirror], right - i);
            while(st[i + 1 + lps[i]] == st[i - 1 - lps[i]]) lps[i] ++;
            if(i + lps[i] > right){
                center = i;
                right = i + lps[i];
            }
        }
        int best_len = 0, best_idx;
        for(int j = 0; j < st.size(); j ++){
            if(lps[j] > best_len){
                best_len = lps[j];
                best_idx = j;
            }
        }
        cout << best_len << " ";
    }
    cout << endl;
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