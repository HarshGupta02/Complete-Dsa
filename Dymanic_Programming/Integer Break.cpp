class Solution {
public:
    
    vector<int>dp;
    
    int f(int &curr, int n, int &ans){
        if(curr < 0) return 0;
        if(curr == 0) return 1;
        if(dp[curr] != -1) return dp[curr];
        int a = 1;
        for(int i = 1; i <= n - 1; i ++){
            if(i > curr) continue;
            curr -= i;
            a = max(a, i * f(curr, n, ans));
            curr += i;
        }
        return dp[curr] = a;
    }
    
    int integerBreak(int n) {
        dp.resize(59, -1);
        int ans = 1, curr = n;
        return f(curr, n, ans);
    }
};

/*

10 =>
1 + 9 = 9
2 + 8 = 16
3 + 7 = 21
4 + 6 = 24
5 + 5 = 25

1. seeing constraints, can use recursion.
*/