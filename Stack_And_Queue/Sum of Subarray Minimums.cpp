class Solution {
public:
    using ll = long long int;
    static const ll MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& heights) {
        ll n = heights.size();
        stack<ll> stk;
        int ans = 0;
        for(ll i = 0; i <= n; i ++) {
            while(!stk.empty() and (i == n or heights[stk.top()] > heights[i])) {
                ll height = heights[stk.top()];
                ll idx = stk.top(); stk.pop();
                ll left = -1, right = i;
                if(!stk.empty()) left = stk.top();
                ll total = ((idx - left) * (right - idx)) % MOD;
                ll p = (height * total) % MOD;
                ans = (ans + p) % MOD;
            }
            stk.push(i);
        }
        return ans;
    }
};

/* 
find first element smaller on the right and first element
smaller on the left
*/
