class Solution {
public:
    
    bool check(int n, int mid, vector<int> &nums, int m){
        int cnt = 1, sum = 0;
        for(int i = 0; i < n ; i ++){
            sum += nums[i];
            if(sum > mid){
                cnt ++;
                sum = nums[i];
            }
        }
        if(cnt <= m) return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum += it;
        int nax = *max_element(nums.begin(), nums.end());
        int low = nax, high = sum;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(n, mid, nums, m)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};

/*

let the largest sum among m subarrays be let us say is x.

x1, x2, x3..

x1 <= x and x2 <= x and x3 <= x .... xm <= x

x1 + x2 ...  + xm <= x * m => sum <= x * m

7,2,5,10,8 

sum = 7 + 2 + 5 + 10 + 8 => 32


*/

    