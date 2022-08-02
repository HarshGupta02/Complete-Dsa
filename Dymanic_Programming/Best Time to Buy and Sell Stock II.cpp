class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int buy = prices[0];
        for(int i = 1; i < n ; i ++){
            if(prices[i] > prices[i - 1]) continue;
            ans += prices[i - 1] - buy;
            buy = prices[i];
        }
        if(prices[n - 1] > buy) ans += prices[n - 1] - buy;
        return ans;
    }
};