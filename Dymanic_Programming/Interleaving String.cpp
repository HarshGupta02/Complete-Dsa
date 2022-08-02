class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if((n1 + n2) != n3) return false;
        vector<vector<bool>>dp(n1 + 1, vector<bool>(n2 + 1));
        dp[0][0] = true;
        for(int i = 1; i <= n2; i ++) dp[0][i] = (s2[i - 1] == s3[i - 1] and dp[0][i - 1] == true);
        for(int i = 1; i <= n1; i ++) dp[i][0] = (s1[i - 1] == s3[i - 1] and dp[i - 1][0] == true);
        for(int i = 1; i <= n1; i ++){
            for(int j = 1; j <= n2; j ++){
                if(s1[i - 1] != s3[i + j - 1] and s2[j - 1] != s3[i + j - 1]) dp[i][j] = false;
                else if(s1[i - 1] == s3[i + j - 1] and s2[j - 1] != s3[i + j - 1]){
                    if(dp[i - 1][j] == true) dp[i][j] = true;
                    else dp[i][j] = false;
                }else if(s2[j - 1] == s3[i + j - 1] and s1[i - 1] != s3[i + j - 1]){
                    if(dp[i][j - 1] == true) dp[i][j] = true;
                    else dp[i][j] = false;
                }else{
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};