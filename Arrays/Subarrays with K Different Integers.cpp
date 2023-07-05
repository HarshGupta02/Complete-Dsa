class Solution {
public:
    int atMost(vector<int> &arr, int n, int k) {
        if(k == 0) return 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;
        while(i < n and j < n) {
            mp[arr[j]] ++;
            while(mp.size() > k) {
                mp[arr[i]] --;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i ++;
            }
            ans += (j - i) + 1;
            j ++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        return atMost(arr, n, k) - atMost(arr, n, k - 1);
    }
};