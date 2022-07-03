int maxProfit(vector<int>&price){
    int n = price.size();
    vector<int>dp_prefix(n);
    dp_prefix[0] = 0;
    int mini = price[0];
    for(int i = 1; i < n ; i ++){
        if(price[i] - mini >= dp_prefix[i - 1]){
            dp_prefix[i] = price[i] - mini;
        }else dp_prefix[i] = dp_prefix[i - 1];
        mini = min(mini , price[i]);
    }
    vector<int>dp_suffix(n);
    dp_suffix[n - 1] = 0;
    int maxi = price[n - 1];
    for(int i = n - 2; i >= 0; i --){
        if(maxi - price[i] >= dp_suffix[i + 1]){
            dp_suffix[i] = maxi - price[i];
        }else dp_suffix[i] = dp_suffix[i + 1];
        maxi = max(maxi , price[i]);
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i ++){
        ans = max(ans , dp_prefix[i] + dp_suffix[i]);
    }
    return ans;
}