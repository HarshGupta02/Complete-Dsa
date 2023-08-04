/*
so here we basically see when we arrive at a character so we do dp[i] = 2 * dp[i - 1]
as the current character will either be included or not included in the subsequences
generated till previous character. 

now we check that we this current character has already appeared so all subsequences
before the prev occurence will be present here also again we would be forming 
duplicate subsequences so subtract that many no of subsequences.

*/

class Solution {
public:
    static const int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        unordered_map<char, int> mp;
        for(int i = 1; i <= n; i ++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            char ch = s[i - 1];
            if(mp.find(ch) != mp.end()) {
                int j = mp[ch];
                dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
            }
            mp[ch] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};