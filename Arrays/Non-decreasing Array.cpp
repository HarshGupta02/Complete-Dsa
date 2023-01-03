/*

so if a[i] >= a[i - 1] so continue but if not then we compare a[i] with a[i - 2]
because we know that a[i - 1] >= a[i - 2] and if a[i] >= a[i - 2] so we can
replace a[i - 1] with a[i] and hence will still hold property and if not 
then we can replace a[i] = a[i - 1] as a[i - 2] <= a[i - 1] <= a[i - 1].

*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int change = 0;
        for(int i = 1; i < n; i ++){
            if(nums[i] < nums[i - 1]){
                change ++;
                if(change > 1) return false;
                if(i == 1 or nums[i - 2] <= nums[i]) nums[i - 1] = nums[i];
                else nums[i] = nums[i - 1];
            }
        }
        return true;
    }
};