/*
if there are 2 prefix subarrays that have sum as s1 and s2 and have the same remainder.
s1 = k*n + x, s2 = k*m + y and s2 have more number of elements than s1. so
s2 - s1 = k(m - n) so the subarray between both the prefix subarrays will have sum divisible
by k.

so if mp[rem] > 0 so there are new mp[rem] new suabrrays that have the sum of the subarrays 
divisible by k and then we increment the mp[rem] ++;

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        // mp[rem] = tells number of subarrays that have remainder as rem when the subarray sum
        // is divided by k.
        mp[0] = 1;
        for(int i = 0; i < n; i ++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;
            ans += mp[rem];
            mp[rem] ++;
        }
        return ans;
    }
};

/*
4,5,0,-2,-3,1

METHOD 1:

number of subarrays that end with a[i]
4 => 0
4,5 => 1
4,5,0 => 2
4,5,0,-2 => 0
4,5,0,-2,-3 => 3
4,5,0,-2,-3,1 => 1
=> total = 0 + 1 + 2 + 0 + 3 + 1 => 7

(sum + x) % k == 0

METHOD 2: 

4,5,0,-2,-3,1 => 4,9,9,7,4,5

METHOD 3:

all subarray sums = 
4,
5,9,
0,5,9,
-2,-2,3,7,
-3,-5,-5,0,4,
1,-2,-4,-4,1,5

*/
