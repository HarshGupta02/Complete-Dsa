// METHOD 1:

class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        if(nums[start] == 0) return true;
        vector<bool> seen(n, false);
        queue<int> q;
        q.push(start);
        seen[start] = true;
        while(!q.empty()) {
            int curr_id = q.front(); q.pop();
            int left_id = curr_id - nums[curr_id];
            int right_id = curr_id + nums[curr_id];
            if(left_id >= 0 and !seen[left_id]) {
                if(nums[left_id] == 0) return true;
                seen[left_id] = true;
                q.push(left_id);
            }
            if(right_id < n and !seen[right_id]) {
                if(nums[right_id] == 0) return true;
                seen[right_id] = true;
                q.push(right_id);
            }
        }
        return false;
    }
};

// METHOD 2:

class Solution {
public:
    
    bool go(int n, int start, vector<int> &arr) {
        if(arr[start] == 0) return true;
        int left = start - arr[start], right = start + arr[start];
        arr[start] = n;
        bool ans = false;
        if(left >= 0 and left < n and arr[left] != n) ans |= go(n, left, arr);
        if(right >= 0 and right < n and arr[right] != n) ans |= go(n, right, arr);
        return ans;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return go(n, start, arr);
    }
};