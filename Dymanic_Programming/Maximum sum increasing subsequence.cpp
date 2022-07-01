class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{
	    vector<int>dp(n);
	    dp[0] = arr[0];
	    for(int i = 1; i < n ; i++){
	        int nax = arr[i];
	        for(int j = 0; j < i ; j ++){
	            if(arr[j] < arr[i]){
	                nax = max(nax, dp[j] + arr[i]);
	            }
	        }
	        dp[i] = nax;
	    }
	    return *max_element(dp.begin() , dp.end());
	}  
};