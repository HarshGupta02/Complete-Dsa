// M1 : O(N^2)

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i ++) {
            for(int j = i - 1; j >= 0; j --) {
                if(arr[j] >= arr[i]) continue;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        vector<int> freq(n, 0);
        for(int i = 0; i < n; i ++) {
            bool found = false;
            for(int j = i - 1; j >= 0; j --) {
                if(arr[j] >= arr[i]) continue;
                found = true;
                if(dp[i] == 1 + dp[j]) freq[i] += freq[j];
            }
            if(!found) freq[i] = 1;
        }
        int max_lis = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            if(dp[i] == max_lis) ans += freq[i];
        }
        return ans;
    }
};