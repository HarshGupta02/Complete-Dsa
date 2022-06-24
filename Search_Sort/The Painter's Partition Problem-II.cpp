class Solution
{
  public:
    using ll = long long int;
    
    bool helper(int arr[], int n, int k , ll mid){
        ll cnt = 1 , curr_sum = 0;
        for(int i = 0; i < n ; i ++){
            if(arr[i] > mid) return false;
            if(curr_sum + arr[i] > mid){
                cnt ++; curr_sum = arr[i];
            }else curr_sum += arr[i];
        }
        if(cnt > k) return false;
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        ll sum = 0;
        for(int i = 0 ; i < n ; i ++) sum += arr[i];
        ll low = 0 , high = sum;
        ll ans;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(helper(arr , n , k , mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};