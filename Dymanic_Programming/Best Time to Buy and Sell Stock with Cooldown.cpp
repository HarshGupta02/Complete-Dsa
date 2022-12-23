/*
obsp = old bought state profit, ossp = old sold state profit,
ocsp = old cooldown state profit,
nbsp = new bought state profit and so on......

so nbsp = max(obsp, ocsp - arr[i]) => so either not buy on current day
or buy the current stock by cooldown with previous day.

so nssp = max(obsp + arr[i], ossp) => so either don't sell on current day
or sell by buying on the previous day.

so ncsp = max(ossp, ocsp) => so either continue the cooldown of previous
day or take cooldown by last selling on previous day.

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int obsp = -1 * prices[0], ossp = 0, ocsp = 0;
        for(int i = 1; i < n; i ++){
            int nbsp, nssp, ncsp;

            nbsp = max(ocsp - prices[i], obsp);
            nssp = max(obsp + prices[i], ossp);
            ncsp = max(ossp, ocsp);
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        return max(ossp, ocsp);
    }
};