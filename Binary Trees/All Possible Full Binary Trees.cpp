/*
so the first observation, we see that we can never form full binary tree with even 
number of nodes. for each node, total no of nodes in left subtree and right subtree will be
odd respectively. hence odd(left_subtree) + odd(right_subtree) + 1(root) = odd

now for a particular n, we try all nodes to be the root and hence no of left childs and 
no of right child will be different for different node as root node. so choose that 
partition, where the total no of left childs are odd and total no of right childs are also
odd.

. | . . . . . . . => 1 + 7
. . . | . . . . . => 3 + 5
. . . . . | . . . => 5 + 3
. . . . . . . | . => 7 + 1

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
    
    vector<TreeNode*> go(int n) {
        if(n == 1) return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 1; i < n; i += 2) {
            auto l = go(i);
            auto r = go(n - i - 1);
            for(auto it1 : l) {
                for(auto it2 : r) {
                    TreeNode* node = new TreeNode(0);
                    node -> left = it1;
                    node -> right = it2;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return go(n);
    }
};