/* 
1. proper prefix is any prefix of the string except the whole string itself.
2. LPS = length of the longest proper prefix which is also a proper suffix.
3. the proper prefix and proper suffix can overlap and both are compared in increasing order of 
their indices.

TIME = O(M + N), SPACE = O(M + N)

*/

ll fast_exp(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = res * a;
        }
        b>>=1;
        a = a * a;
    }
    return res;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> kmp(string s){
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1, len = 0;
    while(i < n){
        if(s[i] == s[len]){
            len ++;
            lps[i] = len;
            i ++;
        }else{
            if(len > 0) len = lps[len - 1];
            else{
                lps[i] = 0;
                i ++;
            }
        }
    }
    return lps;
}

void solve(){
    string text, pattern;
    cin >> text >> pattern;
    int m = text.size(), n = pattern.size();
    string combine = pattern + "#" + text;
    vector<int> lps = kmp(combine);
    vector<int> occ;
    for(int i = 0; i < lps.size(); i ++){
        if(lps[i] == n) occ.push_back(i - n - 1);
    }
    // occ returns an array with elements as the index where the pattern occurs in the text.
    for(auto it : occ) cout << it << " ";
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