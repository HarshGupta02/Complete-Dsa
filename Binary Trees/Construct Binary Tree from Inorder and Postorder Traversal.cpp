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
here we first see that the last element in postorder is the root of the tree and then we locate 
it in inorder and elements to it's right in inorder form the left subtree and those may number of
elements in postorder also form the left subtree and then we recursively calculate the root of the 
subproblem and assign the paren't left to the current root and same goes for the right subtree
of the parent node.
*/

class Solution {
public:
    
    TreeNode* f(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, unordered_map<int,int> &mp){
        if(is > ie or ps > pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int located = mp[postorder[pe]];
        int to_left = located - is;
        root -> left = f(inorder, is, located - 1, postorder, ps, ps + to_left - 1, mp);
        root -> right = f(inorder, located + 1, ie, postorder, ps + to_left, pe - 1, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i ++) mp[inorder[i]] = i;
        return f(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};