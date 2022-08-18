class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    {
        unordered_map<int,int>mp;
        vector<int>prefix_sum(n,0);
        int sum = 0;
        for(int i = 0; i < n; i ++){
            sum += a[i];
            prefix_sum[i] = sum;
            mp[sum] = i + 1;
        }
        int ans = 0;
        for(int i = 0; i < n ; i ++){
            int to_find = prefix_sum[i] + k;
            if(k == prefix_sum[i]) ans = max(ans, i + 1);
            if(mp[to_find] != 0){
                int idx = mp[to_find] - 1;
                ans = max(ans, idx - i);
            }
        }
        return ans;
    } 

};