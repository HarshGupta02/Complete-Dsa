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

/*

so here we basically try to find the width of each level by finding the index of the first and the last node in each level
and then subtract to get width. so we use i -> (2 * i + 1, 2 * i + 2) (0-based indexing). but it can lead to integer overflow
for skewed tree so we subtract the index of all nodes by the min value(or the first value) to get values like 0,1,2,...
then we simply keep on pushing the not null entries.

*/

class Solution {
public:
    using ll = long long int;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        int max_depth = 1;
        while(!q.empty()) {
            int sz = q.size();
            int first_index = q.front().second, last_index = q.back().second;
            max_depth = max(max_depth, last_index - first_index + 1);
            while(sz --) {
                auto curr = q.front(); q.pop();
                ll curr_index = curr.second - first_index;
                TreeNode* curr_node = curr.first;
                if(curr_node -> left != nullptr) q.push({curr_node -> left, (ll)2 * curr_index + 1});
                if(curr_node -> right != nullptr) q.push({curr_node -> right, (ll)2 * curr_index + 2});
            }
        }
        return max_depth;
    }
};
