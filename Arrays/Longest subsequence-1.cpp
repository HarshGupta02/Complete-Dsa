/*
Here each element in the map stores the length of the max subsequence that ends at the curr 
element.
=> In unordered map, find operation takes O(1) time.
*/

class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int curr = 0;
            if(mp.find(a[i] - 1) != mp.end()) curr = max(curr, mp[a[i] - 1]);
            if(mp.find(a[i] + 1) != mp.end()) curr = max(curr, mp[a[i] + 1]);
            mp[a[i]] = curr + 1; ans = max(ans, curr);
        }
        return ans + 1;
    }
};