/// METHOD 1:

class Solution{
public:

    bool isPalindrome(string s){
        string temp = s;
        reverse(temp.begin() , temp.end());
        return (temp == s);
    }
    
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>>dp(n , vector<int>(n));
        for(int gap = 0 ; gap < n ; gap ++){
            for(int i = 0 , j = gap ; j < n ; i++ , j ++){
                if(gap == 0){
                    dp[i][j] = 0; continue;
                }
                if(gap == 1){
                    if(str[i] == str[j]) dp[i][j] = 0;
                    else dp[i][j] = 1; continue;
                }
                string temp = str.substr(i , j - i + 1);
                if(isPalindrome(temp)) dp[i][j] = 0;
                else{
                    int mini = INT_MAX;
                    for(int par = 0 ; par <= j - i - 1 ; par ++){
                        mini = min(mini , 1 + dp[i][i + par] + dp[i + par + 1][j]);
                    }
                    dp[i][j] = mini;
                }
            }
        }
        return dp[0][n - 1];
    }
};

/// METHOD 2:

class Solution{
public:
    
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<bool>>vis(n , vector<bool>(n));
        for(int gap = 0 ; gap < n ; gap ++){
            for(int i = 0 , j = gap ; j < n ; i ++ , j ++){
                if(gap == 0){
                    vis[i][j] = true; continue;
                }
                if(gap == 1){
                    if(str[i] == str[j]) vis[i][j] = true;
                    else vis[i][j] = false; continue;
                }
                if(str[i] == str[j] and vis[i + 1][j - 1] == true) vis[i][j] = true;
                else vis[i][j] = false;
            }
        }
        vector<vector<int>>dp(n , vector<int>(n));
        for(int gap = 0 ; gap < n ; gap ++){
            for(int i = 0 , j = gap ; j < n ; i++ , j ++){
                if(gap == 0){
                    dp[i][j] = 0; continue;
                }
                if(gap == 1){
                    if(str[i] == str[j]) dp[i][j] = 0;
                    else dp[i][j] = 1; continue;
                }
                if(vis[i][j]) dp[i][j] = 0;
                else{
                    int mini = INT_MAX;
                    for(int par = 0 ; par <= j - i - 1 ; par ++){
                        mini = min(mini , 1 + dp[i][i + par] + dp[i + par + 1][j]);
                    }
                    dp[i][j] = mini;
                }
            }
        }
        return dp[0][n - 1];
    }
};


// METHOD 3:

class Solution{
public:
    
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<bool>>vis(n , vector<bool>(n));
        for(int gap = 0 ; gap < n ; gap ++){
            for(int i = 0 , j = gap ; j < n ; i ++ , j ++){
                if(gap == 0){
                    vis[i][j] = true; continue;
                }
                if(gap == 1){
                    if(str[i] == str[j]) vis[i][j] = true;
                    else vis[i][j] = false; continue;
                }
                if(str[i] == str[j] and vis[i + 1][j - 1] == true) vis[i][j] = true;
                else vis[i][j] = false;
            }
        }
        
        vector<int>dp(n);
        dp[0] = 0; 
        for(int j = 1; j < n ; j ++){
            if(vis[0][j]){
                dp[j] = 0; continue;
            }
            int mini = INT_MAX;
            for(int i = j; i >= 1; i --){
                if(!vis[i][j]) continue;
                mini = min(mini , 1 + dp[i - 1]);
            }
            dp[j] = mini;
        }
        return dp[n - 1];
    }
};