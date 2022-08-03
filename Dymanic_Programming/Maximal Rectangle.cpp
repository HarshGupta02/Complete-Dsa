// METHOD 1: TIME = O(N * M) , SPACE = O(M) - APPROX.

/*
HERE WE NEED TO FIND THE MAX AREA OF RECTANGLE WITH ALL ONE'S AND SO EACH 
ELEMENT WITH VALUE 1 CAN BE TREATED AS A TOWER OF HEIGHT 1 AND FOR EACH ROW
AS WE GO DOWN , THE NUMBER OF CONTINOUS ONE'S KEEP ON INCREASING ELSE IF A[I] = 0
SO HEIGHT OF TOWER BECOMES 0.

HERE THE HEIGHT OF EACH TOWER CAN BE CONSIDERED TO BE MADE UP OF 1'S AND SO WE CAN ENSURE
THAT THE AREA UNDER HISTOGRAM WILL BE A RECTANGLE WITH ALL 1'S.
*/

using ll = long long int;
class Solution {
public:
    
    int area(vector<int> arr, int n){
        vector<int>prefix(n),suffix(n);
        stack<int>stk,stk1;
        for(int i = 0; i < n ; i ++){
            if(stk.empty()){
                stk.push(i); continue;
            }
            while(!stk.empty() and arr[i] < arr[stk.top()]){
                prefix[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            prefix[stk.top()] = n;
            stk.pop();
        }
        
        
        for(int i = n - 1; i >= 0 ; i --){
            if(stk1.empty()){
                stk1.push(i); continue;
            }
            while(!stk1.empty() and arr[i] < arr[stk1.top()]){
                suffix[stk1.top()] = i;
                stk1.pop();
            }
            stk1.push(i);
        }
        while(!stk1.empty()){
            suffix[stk1.top()] = -1;
            stk1.pop();
        }
        
        
        ll nax = -1;
        for(int i = 0; i < n ; i ++){
            ll curr = 0;
            curr = (prefix[i] - i) * arr[i] + (i - suffix[i]) * arr[i] - arr[i];
            nax = max(nax , curr);
        }
        return nax;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>v(m,0);
        int maxi = -1;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(matrix[i][j] == '1') v[j] ++;
                else v[j] = 0;
            }
            int Area = area(v, m);
            maxi = max(maxi, Area);
        }
        return maxi;
    }
};

// METHOD 2: TIME = O(N * M) , SPACE = O(M);

class Solution {
public:
    
    int Max_Histogram(vector<int> height){
        stack<int>stk;
        int n = height.size();
        int ans = -1;
        for(int i = 0; i <= n; i ++){
            while(!stk.empty() and (i == n or height[stk.top()] > height[i])){
                int h = height[stk.top()];
                stk.pop();
                int w;
                if(stk.empty()) w = i;
                else w = i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>dp(m, 0);
        int ans = -1;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(matrix[i][j] == '1') dp[j] ++;
                else dp[j] = 0;
            }
            int Area = Max_Histogram(dp);
            ans = max(ans, Area);
        }
        return ans;
    }
};