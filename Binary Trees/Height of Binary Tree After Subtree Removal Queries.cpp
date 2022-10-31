/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root, int level, int &start, vector<int> &euler, vector<int> &depth, map<int, pair<int,int>> &mp){
        if(root == NULL) {
            start -= 1; 
            return;
        }
        euler.push_back(root -> val);
        depth.push_back(level);
        mp[root -> val].first = start;
        start += 1;
        dfs(root -> left, level + 1, start, euler, depth, mp);
        start += 1;
        dfs(root -> right, level + 1, start, euler, depth, mp);
        mp[root -> val].second = start;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int m = queries.size();
        vector<int> euler, depth;
        map<int, pair<int,int>>mp;
        int start = 0;
        dfs(root, 0, start, euler, depth, mp);
        int n = euler.size();
        vector<int>prefix_max(n, 0), suffix_max(n, 0);
        prefix_max[0] = depth[0];
        for(int i = 1; i < n; i ++){
            prefix_max[i] = max(prefix_max[i - 1], depth[i]);
        }
        suffix_max[n - 1] = depth[n - 1];
        for(int i = n - 2; i >= 0; i --){
            suffix_max[i] = max(suffix_max[i + 1], depth[i]);
        }
        vector<int> ans;
        for(int i = 0; i < m; i ++){
            int left = mp[queries[i]].first, right = mp[queries[i]].second;
            int nax = -1;
            if(left - 1 >= 0) nax = max(nax, prefix_max[left - 1]);
            if(right + 1 < n) nax = max(nax, suffix_max[right + 1]);
            ans.push_back(nax);
        }
        return ans;
    }
};

/*
1. each node stores the value 0 or 1 which indicates that whether there exists an alternative path to reach the max height of the 
binary tree. so if the query lies on 1 so the ans is max of (max_left_subtree height, max_right_subtree height) of the 
root node else the ans is max(left - max(node) - 1, right) or (left, right - max(node) - 1).

2. if we take the height of each node, then on deletion, we have to
update the height of all the nodes which are above it so takes time
so we could store the depth of each node and depth never changes for
above nodes, if we delete a certain node.

3. then we convert the given tree into a simple array using euler tour(normal dfs) and normal dfs ensures that all the nodes of
a subtree are covered before moving to it's upper nodes. so in the final array, we have a subarray of nodes within the same subtree
and now the ans will be the max depth of all nodes not included in the subarray and this can be done using prefix and suffix max.
qi = max(prefix_max[l - 1], suffix_max[r + 1]);

*/