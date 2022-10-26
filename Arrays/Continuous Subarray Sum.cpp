/* TIME = O(N), SPACE = O(N)
here we use the concept that we find the prefix sum and keep on finding the 
remainder with k and store in a map. if we already have a prefix sum with the
same remainder beforehand then there was a subarray which was divisible by k
and that's why the remainder was not changed.
*/ 

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end()){ // O(1)
                if(i - mp[rem] >= 2) return true;
            }else{
                mp[rem] = i;
            }
        }
        return false;
    }
};