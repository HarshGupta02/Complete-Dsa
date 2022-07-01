class Solution{
    public:
    using ll = long long int;
    long long maxSubarraySum(int arr[], int n){
        ll curr = 0 , glob_max = -1e18;
        for(int i =0 ; i < n ; i ++){
            curr += arr[i];
            glob_max = max(glob_max, curr);
            if(curr < 0) curr = 0;
        }
        return glob_max;
    }
};