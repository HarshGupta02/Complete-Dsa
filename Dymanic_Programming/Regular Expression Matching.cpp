/*
here if in pattern , there is a '.' so it can be replaced with any character except
empty character. if there is a '*' so the previous character before '*' can be written
as many times as we want in place of (prev_char and '*'). 

1. two empty strings will always match hence dp[0][0] = true.
2. if pattern is empty , then no char matches pattern hence dp[0][1....sz] = false.
3. if text string is empty ->
   a) if pattern is '*' so it can best contribute by appending zero prev_char.
   and look for ans of dp[i - 2][0] as both prev_char and '*' will disappear.
   b) if pattern is a char or '.' so it will never match empty string (text) so
   dp[i][0] = false;
4. if p[i - 1] = '*' so instead of considering all possible lenghts of prev_char, 
we can just see 2 cases -> a) either not include both of them (dp[i - 2][j]), 
b) else save both the char and also append a new prev_char before the '*'. if this 
new prev_char maches the s[j - 1] so dp[i][j] = dp[i - 1][j] or dp[i - 2][j] . 
here dp[i - 1][j] because if both their last char mathces , then we can append as many
prev_char's as we want by looking at the test string and we can consider all possible
pattern's of '*' by recursively considering both the cases.
 

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_sz = s.size(), p_sz = p.size();
        vector<vector<bool>>dp(p_sz + 1, vector<bool>(s_sz + 1));
        for(int i = 0; i <= p_sz; i ++){
            for(int j = 0; j <= s_sz; j ++){
                if(i == 0 and j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0) dp[i][j] = (p[i - 1] == '*' ? dp[i - 2][j] : false);
                else{
                    if(p[i - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                    else if(p[i - 1] != '*' and p[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else if(p[i - 1] != '*' and p[i - 1] != s[j - 1]) dp[i][j] = false;
                    else{
                        dp[i][j] = dp[i - 2][j];
                        if(p[i - 2] == s[j - 1] or p[i- 2] == '.') dp[i][j] = dp[i][j] or dp[i][j - 1];
                    }
                }
            }
        }
        return dp[p_sz][s_sz];
    }
};