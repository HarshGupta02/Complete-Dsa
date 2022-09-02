/*

[0,1,2,2,3,0,4,2] => [0,1,_,_,3,0,4,_]
1. approach 1: try to sort the array and so the removed elements come at last
as they are assigned max value so we pop them back.
2. 2 pointer approach = try to bring the numbers with "val" at the last and 
then remove all of them from the back.

*/

// TIME = O(N * LOGN), SPACE = O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            if(nums[i] == val) nums[i] = INT_MAX;
        }
        sort(nums.begin(), nums.end());
        while(!nums.empty() and nums.back() == INT_MAX) nums.pop_back();
        return (int)nums.size();
    }
};

// TIME = O(N), SPACE = O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            if(nums[left] != val){
                left ++; continue;
            }
            if(nums[right] == val){
                right --; continue;
            }
            swap(nums[left], nums[right]);
            left ++; right --;
        }
        while(!nums.empty() and nums.back() == val) nums.pop_back();
        return (int) nums.size();
    }
};