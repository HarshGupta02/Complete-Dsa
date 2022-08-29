// TIME = O(N), SPACE = O(N)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int start = n - (k % n);
        if(n == 1 or start == n) return;
        int i = start;
        vector<int>ans; ans.push_back(nums[i]);
        i = (i + 1) % n;
        while(i != start) {
            ans.push_back(nums[i]);
            i = (i + 1) % n;
        }
        nums = ans;
    }
};

// TIME = O(N), SPACE = O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// 7 6 5 4 3 2 1 => 5 6 7 1 2 3 4