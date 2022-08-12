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

/// METHOD 1: 
class Solution {
public:
    
    void dfs(TreeNode* root, int &max_depth, int curr){
        if(root == NULL) return;
        max_depth = max(max_depth, curr);
        dfs(root -> left, max_depth, curr + 1);
        dfs(root -> right, max_depth, curr + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int max_depth = 0, curr = 0;
        dfs(root, max_depth, curr);
        queue<pair<TreeNode*, int>>q;
        q.push({root, curr});
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            TreeNode* temp = current.first;
            int lvl = current.second;
            if(lvl == max_depth){
                return temp -> val;
            }
            if(temp -> left != NULL) q.push({temp -> left, lvl + 1});
            if(temp -> right != NULL) q.push({temp -> right, lvl + 1});
        }
        return -1;
    }
};

// METHOD 2:

/*
as we need the leftmost node of the last row, so we keep on storing the right
elements first and then the left elements and at the last we will be left with 
the leftmost node of the last row.
*/


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* ans;
        while(!q.empty()){
            ans = q.front();
            q.pop();
            if(ans -> right != NULL) q.push(ans -> right);
            if(ans -> left != NULL) q.push(ans -> left);
        }
        return ans -> val;
    }
};