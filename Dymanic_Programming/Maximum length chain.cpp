/// TIME = O(N ^ 2), SPACE = O(N)

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


// TIME = O(N * LOGN), SPACE = O(1)

class Solution{
public:
    /*You are required to complete this method*/
    
    static bool cmp(const val &a, const val &b){
        return a.second < b.second;
    }
    
    int maxChainLen(struct val p[],int n){
        sort(p, p + n, cmp);
        int ans = 1;
        int glob_start = p[0].first, glob_end = p[0].second;
        for(int i = 1; i < n ; i ++){
            if(p[i].first > glob_end){
                ans ++;
                glob_start = p[i].first;
                glob_end = p[i].second;
            }
        }
        return ans;
    }
};