// TIME = O(N ^ 2), SPACE = O(N ^ 2)

// s = "babgbag"
// t = "bag"
    
// if(s[i] == t[j]) so dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
// else dp[i][j] = dp[i - 1][j]

class Solution {
public:
    using ll = long long int;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int> (m, 0));
        if(s[0] == t[0]) dp[0][0] = 1;
        else dp[0][0] = 0;
        for(int i = 1; i < n; i ++){
            if(s[i] == t[0]) dp[i][0] = 1 + dp[i - 1][0];
            else dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i < n; i ++){
            for(int j = 1; j < m; j ++){
                if(s[i] == t[j]) 
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};

// TIME = O(N ^ 2), SPACE = O(2 * N) ~ O(N)

class Solution {
public:
    using ll = long long int;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned int> prev(m, 0), curr(m, 0);
        prev[0] = (s[0] == t[0] ? 1 : 0);
        for(int i = 1; i < n; i ++){
            if(s[i] == t[0]) curr[0] = 1 + prev[0];
            else curr[0] = prev[0];
            for(int j = 1; j < m; j ++){
                if(s[i] == t[j]) 
                    curr[j] = prev[j - 1] + prev[j];
                else 
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};
