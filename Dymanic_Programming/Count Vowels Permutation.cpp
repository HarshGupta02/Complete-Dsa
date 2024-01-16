// METHOD 1:

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<char>vowels = {'#','a','e','i','o','u'};
    vector<vector<int>>v;
    
    void precompute(){
        v.resize(6);
        for(int i = 1; i <= 5; i ++){
            char curr = vowels[i];
            if(curr == 'a') v[1] = {2}; 
            else if(curr == 'e') v[2] = {1,3};
            else if(curr == 'i') v[3] = {1,2,4,5};
            else if(curr == 'o') v[4] = {3,5};
            else v[5].push_back(1);
        }
    }
    
    int countVowelPermutation(int n) {
        precompute();
        vector<vector<int>>dp(n + 1, vector<int>(6,0));
        for(int i = 1; i <= 5;i ++) dp[1][i] = 1;
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= 5; j ++){
                for(auto c : v[j]) dp[i][j] = (dp[i][j] + dp[i - 1][c]) % MOD;
            }
        }
        int total = 0;
        for(int i = 1; i <= 5; i ++) total = (total + dp[n][i]) % MOD;
        return total;
    }
};

// METHOD 2:

