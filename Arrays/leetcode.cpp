#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    
    int go(int i, int curr, int cnt, int n, string &s) {
        if(i <= 0) return 0;
        int ans = INT_MAX;
        if(s[i] == '1') {
            curr += (1 << cnt);
            ans = min(ans, go(i - 1, curr, cnt + 1, n, s));
            curr -= (1 << cnt);            
            ans = min(ans, 1 + go(i - 1, 0, 0, n, s));
        }else {
            ans = min(ans, go(i - 1, curr, cnt + 1, n, s));
        }
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        int curr = 0, cnt = 0;
        return go(n - 1, curr, cnt, n, s);
    }
};

void solve(){
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minimumBeautifulSubstrings(s) << "\n";
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

class DSU{
    public:
    
    vector<int>parent, rank;
    
    DSU(int n){
        parent.resize(n); rank.resize(n, 0);
        for(int i = 0; i < n ; i ++) parent[i] = i;
    }
    
    int get_parent(int a){
        return parent[a] = (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void Merge(int a, int b){
        a = get_parent(a);
        b = get_parent(b);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
    
};