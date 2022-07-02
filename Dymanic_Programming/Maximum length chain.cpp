bool cmp(const val &a , const val &b){
    return a.first < b.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p , p + n , cmp); /// why sorted ??
    vector<int>dp(n , 1);
    for(int i = 1; i < n ; i++){
        int nax = 1;
        for(int j = 0 ; j < i ; j ++){
            if(p[j].second < p[i].first) nax = max(nax, 1 + dp[j]);
        }
        dp[i] = nax;
    }
    return *max_element(dp.begin(),dp.end());
}