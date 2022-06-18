#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// it uses rolling Hash function but here we have precalculates the hash values of the prefix of the strings T in which 
// the pattern has to be searched.

/// h(s[0 .... n - 1]) = s[0] * 1 + s[1] * p + s[2] * p^2 + s[3] * p^3 .... + s[n - 1] * p^(n - 1). -----> (1)
/// h(s[i .... j]) = s[i] + s[i + 1] * p + s[i + 2] * p^2 + s[i + 3] * p^3 .... + s[j] * p^(j - i). -----> (2)

/// multiplying eq (2) with p^i

/// h(s[i ....j]) * p^i = s[i] * p^i + s[i + 1] * p^(i + 1) + s[i + 2] * p^(i + 2) ....
/// ==>  h(s[0 ..... j]) - h(s[0 .... i]).

vector<int> Rabin_Karp(string const& s , string const& t){
    const int p = 31; /// take a prime number >= no of possible entities like for small case letters (26) take p = 31 and for 
    /// small + upper case letters(52) take p = 53.
    const int m = 1e9 + 9; /// take a prime number not much large.
    int S = s.size() , T = t.size();
    vector<ll>p_pow(max(S,T)); // powers will be 0 to max(S,T) - 1. 
    p_pow[0] = 1;
    for(int i = 1; i < (int)p_pow.size(); i ++){ // precompute powers of p.
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }
    vector<ll>h(T+1 , 0); /// prefix hash
    for(int i = 0; i < T; i++){
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }
    ll h_s = 0; // pattern hash
    for(int i = 0; i < S; i++){
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    vector<int>occurences;
    for(int i = 0; i + S - 1 < T; i++){ // check the hash value of every possible substring of length S.
        ll curr_h = (h[i + S] + m - h[i]) % m; /// (a - b) % m = (a + m - b) % m if (a - b > m)
        if(curr_h == h_s * p_pow[i] % m)
            occurences.push_back(i);            
    }
    return occurences; // return the indices in t(string) where we will find s(string).
}


void solve(){
    vector<int>ans = Rabin_Karp("aaba" , "aabaacaadaabaaba");
    for(auto it : ans) cout << it << " ";
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
