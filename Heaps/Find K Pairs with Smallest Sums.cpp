/*
so here basically, we use the same concept as that of merging k sorted lists. so we
basically, first insert the head of one element with all pairs of other elements in 
the other array and then keep on popping the one with the smallest sum and insert the new 
pair adjacent to it only as it is sorted.

*/

class cmp{
public:
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return (a[0] + a[1]) > (b[0] + b[1]);
    }
};

class Solution {
public:
    using vi = vector<int>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<vi, vector<vi>, cmp> pq;
        for(int i = 0; i < min(n, k); i ++) pq.push({nums1[i], nums2[0], 0});
        vector<vi> ans;
        while(!pq.empty() and k --) {
            vi curr = pq.top(); pq.pop();
            ans.push_back({curr[0], curr[1]});
            int curr_idx = curr[2];
            if(curr_idx == m - 1) continue;
            pq.push({curr[0], nums2[curr[2] + 1], curr[2] + 1});
        }
        return ans;
    }
};