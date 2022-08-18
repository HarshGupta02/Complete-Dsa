/*

[a,b,c,d...] => [x,x,x,x....]

sum = a + b + c + d ...

in 1 move , total sum of all elements increase by n - 1.

so after m moves, total = sum + m * (n - 1) = x * n

=> sum + m * (n - 1) = x * n

and x = min_num + m

2 -> 3 -> 4 -> 5 -> 6

sum + m * n - m = (min_num + m) * n

=> m = sum - (n * min_num);

*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum += it;
        int mini = *min_element(nums.begin(), nums.end());
        return sum - (n * mini);
    }
};
