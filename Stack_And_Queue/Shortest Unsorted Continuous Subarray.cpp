/*
METHOD 1: here we see that if an array is not sorted then there exists atleast 2 
elements(x,y) such that x comes before y but x > y. so there exists an element which
is smaller that than max elements to the left and there exists an element which is
larger than min elements to the right(because this only caused the discrepency of 
non ascending order). so we try to find the subarray which is largest in terms that
it covers all such elements.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i ++){
            if(maxi > nums[i]) right = i;
            else maxi = nums[i];
        }
        for(int i = n - 1; i >= 0; i --){
            if(nums[i] > mini) left = i;
            else mini = nums[i];
        }
        if(left == -1 and right == -1) return 0;
        return right - left + 1;
    }
};