/*
here we first sort the array and then find the media of the array and it is 
correct because if an element occurs more numbe rof times so it's chances to
become a median increases and hence the cost of the operations decreases.
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n % 2 == 1){
            int mid = nums[n/2];
            int ans = 0;
            for(int i = 0; i < n; i ++) ans += abs(nums[i] - mid);
            return ans;
        }else{
            int mid1 = nums[n/2 - 1], mid2 = nums[n/2];
            int curr = 0, ans = 0;
            for(int i = 0; i < n; i ++) curr += abs(nums[i] - mid1);
            ans = curr; curr = 0;
            for(int i = 0; i < n; i ++) curr += abs(nums[i] - mid2);
            ans = min(ans, curr);
            return ans;
        }
    }
};