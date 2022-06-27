#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string s;
string res = "";

bool IsOperand(char c){
    return ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'));
}

int precedence(char c){
    if(c == '^') return 3;
    else if(c == '*' or c == '/') return 2;
    else if(c == '+' or c == '-') return 1;
    return -1;
}

void InfixToPrefix(){
    stack<char>stk;
    reverse(s.begin() , s.end());
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
        if(s[i] == ')') s[i] = '(';
        else if(s[i] == '(') s[i] = ')';
        else continue;
    }
    s = '(' + s + ')';
    for(int i = 0; i < n + 2 ; i ++){
        char c = s[i];
        if(c == '('){
            stk.push(c); continue;
        }
        if(c == ')'){
            while(stk.top() != '('){
                res += stk.top();
                stk.pop();
            }
            stk.pop(); continue;
        }
        if(IsOperand(c)){
            res += c; continue;
        }
        while(!stk.empty() and precedence(c) < precedence(stk.top())){
            res += stk.top();
            stk.pop();
        }
        stk.push(c);
    }
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin() , res.end());
}

void solve(){
    cin >> s;
    InfixToPrefix();
    cout << res << endl;
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