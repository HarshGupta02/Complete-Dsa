class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n + 1 , 0);
        vector<int>cut = {x,y,z};
        sort(cut.begin() , cut.end());
        int mini = cut[0];
        for(int i = 0; i <= n ; i++){
            if(i < mini) continue;
            for(int j = 0; j < 3 ; j ++){
                int left = i - cut[j];
                if(left < 0) continue;
                if(left == 0){
                    dp[i] = max(dp[i],1) ; continue;
                }
                if(dp[left] != 0){
                    dp[i] = max(dp[i] , 1 + dp[left]);
                }
            }
        }
        return dp[n];
    }
};