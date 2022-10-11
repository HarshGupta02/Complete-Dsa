/*
here basically we try to find two number lowest and second_lowest such that they are as
minimum as possible so that the coming numbers can be just compared to the second_lowest
and if it is greater than second_lowest then there exists an increasing triplet subsequence.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int lowest = INT_MAX, second_lowest = INT_MAX;
        for(int i = 0; i < n; i ++){
            if(nums[i] <= lowest) lowest = nums[i];
            else if(nums[i] <= second_lowest) second_lowest = nums[i];
            else return true;
        }
        return false;
    }
};