/*
for each position, we try all possible numbers from 1 to 6, then we check the 
last and second last element so that they are not equal to current element and 
the gcd of the current element and the last element is always 1.

second_last, last, i

so dp[i][last][second_last] = tells the number of distinct sequences that last
element is "last" and second last element is "second_last" and the lenght 
of sequence is (n - i).
*/

class Solution {
public:
    
    const int MOD = (int)1e9 + 7;
    const static int MAXN = 1e4 + 5;
    int dp[MAXN][7][7];
    
    int f(int i, int last, int second_last){
        if(i < 0) return 1;
        if(dp[i][last][second_last] != -1) return dp[i][last][second_last];
        int res = 0;
        for(int j = 1; j <= 6; j ++){
            if(__gcd(j, last) == 1 and last != j and second_last != j) res = (res + f(i - 1, j, last)) % MOD;
        }
        return dp[i][last][second_last] = res;
    }
    
    int distinctSequences(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 1; i <= 6; i ++){
            ans = (ans + f(n - 2, i, 0)) % MOD;
        }
        return ans % MOD;
    }
};