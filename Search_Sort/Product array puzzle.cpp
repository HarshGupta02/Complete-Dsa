class Solution{
  public:
    using ll = long long int;
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<ll>prefix(n , 1); prefix[0] = nums.front();
        for(int i = 1; i < n ; i ++) prefix[i] = prefix[i - 1] * nums[i];
        vector<ll>suffix(n , 1); suffix[n - 1] = nums.back();
        for(int i = n - 2; i >= 0 ; i --) suffix[i] = suffix[i + 1] * nums[i];
        vector<ll>ans;
        for(int i = 0; i < n ; i ++){
            ll p = 1;
            if(i - 1 >= 0) p *= prefix[i - 1];
            if(i + 1 < n) p *= suffix[i + 1];
            ans.push_back(p);
        }
        return ans;
    }
};