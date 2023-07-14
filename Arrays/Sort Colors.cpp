/*
so here we maintain 3 pointers (low, mid, high).
[0... low - 1] = contains all 0's
[low...mid - 1] = contains all 1's
[mid....high] = unsorted array
[high + 1...n - 1] = contains all 2's

go until mid becomes higher than high.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low ++; mid ++;
            }else if(nums[mid] == 1) mid ++;
            else {
                swap(nums[mid], nums[high]);
                high --;
            }
        }
    }
};