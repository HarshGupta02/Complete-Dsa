/*
so here we try to maximize the score of the first player and so we always add
the score of the element picked up by the first player and then we subtract the 
score of the first player by the total score and the remaining is the max score
of the second player.
*/

class Solution {
public:
    
    int f(int i, int j, vector<int> &nums, int chance){
        if(i > j) return 0;
        if(chance == 0) return max(nums[i] + f(i + 1, j, nums, 1), nums[j] + f(i, j - 1, nums, 1));
        return min(f(i + 1, j, nums, 0), f(i, j - 1, nums, 0));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int second = 0;
        for(auto it : nums) second += it;
        int first = f(0, n - 1, nums, 0);
        second -= first;
        return (first >= second);
    }
};