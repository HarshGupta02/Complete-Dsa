/*
TIME = O(10 * LOG(MAX(A, B)) * X);

here we use the concept of digit dp. so each time, we try to find the n digit
numbers with sum x so we try to fix the leftmost digit and call the recursive
function for n - 1 digits.

tight is a bool variable which tells that if tight is 1 so we may go beyond our 
desired range of numbers, but if tight is 0 so we can insert any number at the left
most position. 

*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;

// MXN1 = LOG(MAX(A, B)), MXN2 = DESIRED SUM, MXN3 = TIGHT(0, 1).

// int dp[MXN1][MXN2][MXN3]
int dp[101][181][2];

ll f(string &s, int n, int x, bool tight){
    if(n == 1) return (x >= 0 and x <= 9);
    if(dp[n][x][tight] != -1) return dp[n][x][tight];
    int ub = tight ? s[s.size() - n] - '0' : 9;
    ll answer = 0;
    for(int dig = 0; dig <= ub; dig ++){
        answer += f(s, n - 1, x - dig, tight & (dig == ub));
    }
    return dp[n][x][tight] = answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll l, r, x;
    cin >> l >> r >> x;
    string a = to_string(l - 1), b = to_string(r);
    int n1 = a.size(), n2 = b.size();
    memset(dp, -1, sizeof(dp));
    cout << f(b, n2, x, 1) - f(a, n1, x, 1) << "\n";
    return 0;
}