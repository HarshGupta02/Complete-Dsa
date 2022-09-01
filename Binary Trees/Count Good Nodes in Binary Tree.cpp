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
    
    void f(TreeNode* root, int &good, int nax){
        if(root == NULL) return;
        int temp = nax;
        if(root -> val >= nax){
            good ++;
            nax = root -> val;
        }
        f(root -> left, good, nax);
        f(root -> right, good, nax);
    }
    
    int goodNodes(TreeNode* root) {
        int good = 0, nax = -1e5;
        f(root, good, nax);
        return good;
    }
};