/* METHOD 1:

->>>>> not preferred method as should not modify input
so here we modify the input array and convert even numbers to 0 and odd numbers to 1 and find
the number of subarrays with sum k. it works because sum = k in a binary array means k occurence
of 1 and each 1 corresponds to an odd number and even numbers being 0 contributes nothing.

*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i ++) {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()) ans += mp[sum - k];
            mp[sum] ++;
        }
        return ans;
    }
};

// METHOD 2:

class Solution {
public:
    
    int atMost(int n, vector<int>& nums, int k) {
        int i = 0, j = 0;
        int cnt = 0, ans = 0;
        while(i < n and j < n) {
            if(nums[j] % 2) cnt ++;
            while(cnt > k) {
                if(nums[i] % 2) cnt --;
                i ++;
            }
            ans += (j - i) + 1;
            j ++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return atMost(n, nums, k) - atMost(n, nums, k - 1);
    }
};