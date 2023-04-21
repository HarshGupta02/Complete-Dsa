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
    int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root -> right != nullptr) bstToGst(root -> right);
        pre = root -> val = pre + (root -> val);
        if(root -> left != nullptr) bstToGst(root -> left);
        return root;
    }
};

/*
so here we basically need to keep track of sum of the larger elements so we basically do a reverse inorder
traversal which ensures that we always have the sum of all the larger elements to the right.

*/