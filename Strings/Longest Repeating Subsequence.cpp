// TIME = O(N ^ 2) , SPACE = O(N ^ 2)

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<vector<int>>dp(n + 1 , vector<int>(n + 1,INT_MIN));
		    for(int i = 0; i <= n; i++){
		        for(int j = 0; j <= n; j++){
		            if(i == 0 or j == 0) dp[i][j] = 0;
		        }
		    }
		    for(int i = 1; i <= n; i++){
		        for(int j = 1; j <= n; j++){
		            if(i == j) dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		            else{
		                if(str[i - 1] == str[j - 1]){
		                    dp[i][j] = 1 + dp[i - 1][j - 1];
		                }else{
		                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		                }
		            }
		        }
		    }
		    return dp[n][n];
		}

};

/// TIME = O(N ^ 2) , SPACE = O(N)

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<int>prev(n + 1) , curr(n + 1);
		    for(int i = 0; i <= n; i++){
		        prev[i] = 0;
		    }
		    for(int i = 1; i <= n; i++){
		        curr[0] = 0;
		        for(int j = 1; j <= n; j++){
		            if(i == j) curr[j] = max(prev[j] , curr[j - 1]);
		            else{
		                if(str[i - 1] == str[j - 1]){
		                    curr[j] = 1 + prev[j - 1];
		                }else{
		                    curr[j] = max(prev[j] , curr[j - 1]);
		                }
		            }
		        }
		        prev = curr;
		    }
		    return prev[n];
		}

};