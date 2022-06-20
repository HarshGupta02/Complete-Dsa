class Solution{
    using ll = long long int;
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        ll curr_sum = 0 , glob_sum = -1e18;
        for(int i = 0; i < n ; i ++){
            curr_sum += arr[i];
            glob_sum = max(glob_sum , curr_sum);
            if(curr_sum < 0) curr_sum = 0;
        }
        return glob_sum;
    }
};