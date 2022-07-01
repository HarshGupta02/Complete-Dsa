long long int count(long long int n)
{
    vector<long long int>score = {3,5,10};
    vector<long long int>dp(n + 1,0);
    dp[0] = 1;
    for(int j = 0; j < 3; j ++){
        for(int i = 0; i <= n ; i ++){
            if(i >= score[j])
                dp[i] += dp[i - score[j]];
        }
    }
    return dp[n];
}