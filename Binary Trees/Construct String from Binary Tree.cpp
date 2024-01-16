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
before going to each not null node, we insert an opening bracket and 
before leaving a node, we add an closing bracket.

if both left and right child are null => do nothing.
if both are present => add to both
if(left present and right not present) => only for left.
if(left not present and right present) => add () and then to right.

*/

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string s = to_string(root -> val);
        if(root -> left != NULL) s += "(" + tree2str(root -> left) + ")";
        else if(root -> right != NULL) s += "()";
        if(root -> right != NULL) s += "(" + tree2str(root -> right) + ")";
        return s;
    }
};