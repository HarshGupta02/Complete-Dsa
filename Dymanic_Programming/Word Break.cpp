/*
here we try to create the string using dict words and dp[i] = true if we can
create a string starting from ith index and all it's words are part of dict.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m = wordDict.size();
        vector<bool>dp(n + 1,false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; i --){
            for(auto it : wordDict){
                int sz = it.size();
                if(i + sz <= n and s.substr(i,sz) == it)
                    dp[i] = dp[i + sz];
                if(dp[i] == true) break;
            }
        }
        return dp[0];
    }
};