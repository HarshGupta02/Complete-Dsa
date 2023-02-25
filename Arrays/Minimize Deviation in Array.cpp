/*
here we see that an odd number can be multiplied by 2 only once and then it can be 
divided only. so first increase all the numbers to it's max value and then  try
to decrease the numbers as much as possible and keep on storing the min value in the
array and check the difference with the min and the max value.

*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int mini = INT_MAX, diff = INT_MAX;
        for(int i = 0; i < n; i ++){
            if(nums[i] % 2 == 1) nums[i] *= 2;
            mini = min(mini, nums[i]);
            pq.push(nums[i]);
        }
        while(!pq.empty() and pq.top() % 2 == 0){
            int x = pq.top(); pq.pop();
            diff = min(diff, x - mini);
            mini = min(mini, x/2);
            pq.push(x/2);
        }
        return min(diff, pq.top() - mini);
    }
};