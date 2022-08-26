class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        // p1 points to that number with which we have to multiply 2 and same 
        // goes for 3 and 5.
        for(int i = 1; i < n; i ++){
            int a = 2 * dp[p1], b = 3 * dp[p2], c = 5 * dp[p3];
            dp[i] = min(a, min(b, c));
            if(dp[i] == a) p1 ++;
            if(dp[i] == b) p2 ++;
            if(dp[i] == c) p3 ++;
        }
        return dp[n - 1];
    }
};

/*

if a number is already ugly then we can multiply 2 or 3 or 5 to generate a 
new ugly number.

*/