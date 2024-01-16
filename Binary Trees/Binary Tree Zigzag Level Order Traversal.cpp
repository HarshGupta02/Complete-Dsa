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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int chance = 0;
        if(root == NULL) return {};
        ans.push_back({root -> val});
        while(!q.empty()){
            int n = q.size();
            vector<int> current;
            while(n --){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left != NULL) {
                    q.push(curr -> left);
                    current.push_back(curr -> left -> val);
                }
                if(curr -> right != NULL) {
                    q.push(curr -> right);
                    current.push_back(curr -> right -> val);
                }
            }
            if(chance == 0) reverse(current.begin(), current.end());
            chance = 1 - chance;
            ans.push_back(current);
        }
        ans.pop_back();
        return ans;
    }
};