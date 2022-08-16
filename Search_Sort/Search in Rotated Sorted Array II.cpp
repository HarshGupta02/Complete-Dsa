/*

here if a[mid] = a[low] = a[high] so we don't know which side to go so we decrease
our search space by moving low to right and high to left by 1 units.

TIME = O(LOGN) -> BEST CASE,  O(N) -> WORST CASE(when all elements are equal).

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] and nums[mid] == nums[high]){
                low ++; high --;
            }else if(nums[low] <= nums[mid]){
                if(target >= nums[low] and target <= nums[mid]) high = mid - 1;
                else low = mid + 1;
            }else{
                if(target >= nums[mid] and target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};

/*

1. when no duplicates, we tried for possible position of target.
2. when duplicates, so try to reduce search space by moving low and high
closer to each other.

[1,1,1,2,1]
*/