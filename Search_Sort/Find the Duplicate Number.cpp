/*
here we used the fact that if exactly one number appears more than 1 time(2,3,..) then
we will reach the repeating number more than once and this concept is used in the 
cycle method in linked list and for each element an index will exist.

TIME = O(N) , SPACE = O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*

n = 4

[1,3,4,2,2] => 1,2,2,3,4
 1 2 3 4 5  => 1 2 3 4 5
 
 1 2 3 4 5
 1 3 4 2 2 
 
 1 2 3 4 5
 1 2 4 2 2
 
 1. pigeonhole principle confirms that there will be a duplicate.
*/