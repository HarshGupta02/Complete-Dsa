#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    vector<string> expressions = {"<<>>", "<>", "<><>", ">>", "<<>", "><><"};
    vector<int> maxReplacements = {0, 1, 2, 2, 2, 2};
    int n = expressions.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i ++) {
        string s = expressions[i];
        stack<char> stk;
        int m = s.size();
        for(int j = 0; j < m; j ++) {
            if(stk.empty()) stk.push(s[j]);
            else {
                if(stk.top() == '<' and s[j] == '>') stk.pop();
                else stk.push(s[j]);
            }
        }
        int right = 0, left = 0;
        while(!stk.empty()) {
            if(stk.top() == '<') right ++;
            else left ++;
            stk.pop();
        }
        if(right > 0 or left > maxReplacements[i]) ans[i] = 0;
        else ans[i] = 1;
    }
    return ans;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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