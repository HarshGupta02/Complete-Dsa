class Solution
{
    using ll = long long int;
    public:
        bool helper(int mid , int n){
            int cnt = 0;
            int a = 5;
            while((mid/a) != 0){
                cnt += (mid / a);
                a *= 5;
            }
            if(cnt >= n) return true;
            return false;
        }
        int findNum(int n)
        {
            int low = 1 , high = 5 * (n + 1);
            int ans;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(helper(mid , n)){
                    ans = mid;
                    high = mid - 1;
                }else low = mid + 1;
            }
            return ans;
        }
};


//// number of trailing zeros in n! = n/5 + n/25 + n/125 + ....

/// for each n(no of trailing zeros) , we can form it by no : (1 - 5 * (n + 1)) as
/// factorial of numbers in these range will gurantee the number of trailing zeros
/// as n or less than that.
