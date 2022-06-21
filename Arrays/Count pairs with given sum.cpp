class Solution{   
public:
    using ll = long long int;
    
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<ll,ll>mp;
        for(int i =0 ; i <n ; i ++){
            mp[arr[i]] ++;
        }
        ll ans = 0 ;
        for(int i = 0;i < n;i ++){
            if(k - arr[i] <= 0 or mp[k - arr[i]] == 0) continue;
            ans += mp[k - arr[i]];
            if(arr[i] == (k - arr[i])) ans --;
            mp[arr[i]] -- ;
        }
        return ans;
    }
};