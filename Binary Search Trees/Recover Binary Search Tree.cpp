/*
so here we basically see that swapping 2 values disturbs the monotonicity at two positions if we look at the inorder
traversal of the bst. so the first disturbance, we select the first node as swapped one and for the second 
disturbance, we select the second node as the swapped one and we just maintain the previous node for checking the 
last element that occured in the inorder traversal of the tree.

*/

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
    
    TreeNode *first, *last, *middle, *prev;
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root -> left);
        
        if(prev != nullptr and prev -> val > root -> val) {
            if(first == nullptr) {
                first = prev;
                middle = root;
            }else last = root;
        }
        
        prev = root;
        inorder(root -> right);
    }
    
    void recoverTree(TreeNode* root) {
        first = last = middle = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first and last) swap(first -> val, last -> val);
        else swap(first -> val, middle -> val);
    }
};