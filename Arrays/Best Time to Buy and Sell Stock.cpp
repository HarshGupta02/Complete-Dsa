class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best_candidate = prices[0];
        int nax = 0;
        for(int i = 1 ; i < n ; i ++){
            nax = max(nax , prices[i] - best_candidate);
            if(prices[i] < best_candidate){
                best_candidate = prices[i];
            }
        }
        return nax;
    }
};