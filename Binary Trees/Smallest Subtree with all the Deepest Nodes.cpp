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
so we start from root and we see that if the max height of left subtree and max height
of right subtree are equal then this will be our answer and if left subtree is 
bigger then we go to right as deepest nodes will be found on left else on right.
*/

class Solution {
public:
    
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(depth(root -> left), depth(root -> right));
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;
        int l = depth(root -> left);
        int r = depth(root -> right);
        if(l == r) return root;
        if(l > r) return subtreeWithAllDeepest(root -> left);
        return subtreeWithAllDeepest(root -> right);
    }
};