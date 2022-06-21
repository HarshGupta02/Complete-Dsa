class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int>mp;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == 0) return true;
            mp[sum] ++;
        }
        for(auto it : mp){
            if(it.second >= 2) return true;
        }
        return false;
    }
};