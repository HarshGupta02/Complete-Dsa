/*
EACH NUMBER CAN HAVE A MAX OF N^1/3 DIVISORS IN TOTAL.

so we check if we can create all components with value as x by considering all
elements contribution to target. if less than x so edge must not be deleted and 
it must contribute it's value to it's upper parent. and if value of any node inc
luding himself and his childs is greater than the target(x) so it cannot be 
broken into components with sum each of x.

*/

class Solution {
public:
    vector<vector<int>> adj;
    
    int dfs(int src, int par, int target, vector<int> &nums){
        int total = nums[src];
        for(auto neigh : adj[src]){
            if(neigh == par) continue;
            total += dfs(neigh, src, target, nums);
        }
        if(total == target) return 0;
        return total;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), m = edges.size();
        adj.resize(n);
        int sum = 0;
        for(int i = 0; i < n; i ++) sum += nums[i];
        for(int i = 0; i < m; i ++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        // O(N * (N ^ 1/3)) ~~ 2 * 10^6
        for(int parts = 1; parts <= n; parts ++){
            if(sum % parts != 0) continue;
            if(dfs(0, -1, sum/parts, nums) != 0) continue;
            ans = max(ans, parts - 1);
        }
        return ans;
    }
};