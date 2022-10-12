class Solution{
    using ll = long long int;
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        ll curr_sum = 0 , glob_sum = -1e18;
        ll s = 0, st = 0, en = 0;
        for(int i = 0; i < n ; i ++){
            curr_sum += arr[i];
            if(curr_sum > glob_sum){
                glob_sum = curr_sum;
                st = s; en = i;
            }
            if(curr_sum < 0){
                curr_sum = 0;
                s = i + 1;
            }
        }
        cout << "the subarray with max subarray sum is " << endl;
        for(int i = st; i <= en; i ++) cout << arr[i] << " ";
        cout << endl;
        return glob_sum;
    }
};