class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int>dp(N);
        dp[0] = 1;
        for(int i = 1; i < N; i ++){
            int nax = 1;
            for(int j = 0 ; j < i ; j ++){
                if(abs(A[j] - A[i]) == 1){
                    nax = max(nax, dp[j] + 1);
                }
            }
            dp[i] = nax;
        }
        return *max_element(dp.begin(),dp.end());
    }
};