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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder = {};
        if(root == nullptr) return inorder;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(true) {
            if(node != nullptr) {
                stk.push(node);
                node = node -> left;
            }else {
                if(stk.empty()) break;
                node = stk.top(); stk.pop();
                inorder.push_back(node -> val);
                node = node -> right;
            }
        }
        return inorder;
    }
};