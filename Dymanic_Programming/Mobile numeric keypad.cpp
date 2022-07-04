class Solution{
	public:
	
	using ll = long long int;
	long long getCount(int N)
	{
	    vector<vector<ll>>v(10);
	    v[0] = {0,8}; v[1] = {1,2,4}; v[2] = {1,2,3,5}; v[3] = {2,3,6}; v[4] = {1,4,5,7};
	    v[5] = {2,4,5,6,8}; v[6] = {3,5,6,9}; v[7] = {4,7,8}; v[8] = {0,5,7,8,9}; v[9] = {6,8,9};
		vector<vector<ll>>dp(N + 1 , vector<ll>(10,0));
		for(int i = 0 ; i < 10 ;i ++) dp[1][i] = 1;
		for(int i = 2; i <= N ; i ++){
		    for(int j = 0; j < 10; j ++){
		        for(auto it : v[j]){
		            dp[i][j] += dp[i - 1][it];
		        }
		    }
		}
		ll sum = 0;
		for(int i = 0 ; i < 10 ;i ++){
		    sum += dp[N][i];
		}
		return sum;
	}
};