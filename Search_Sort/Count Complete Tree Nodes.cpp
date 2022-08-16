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
TIME = O(LOG N * LOG N) , SPACE = O(LOG N)

here we check for each node whether it's left and right height are same or not.
if they are same so that subtree has all levels completely filled so used the formula
(2^level) - 1. 
else there would be diff of 1 (cannot be more that as it is a complete tree).

so we calculate the number of nodes of left and right subtree and add 1 for current
node and return the amount.

*/
class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int left_height = 0, right_height = 0;
        TreeNode* temp = root;
        while(temp != NULL){
            left_height ++; temp = temp -> left;
        }
        TreeNode* curr = root;
        while(curr != NULL){
            right_height ++; curr = curr -> right;
        }
        if(left_height == right_height) return (1 << left_height) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

/*

0th level = 1
1st level = 2
2nd level = 4
3rd level = 8
4th level = 16

1. first go as left as possible and count the deepest level we can reach.
2. if numbering of nodes is in order so we can go to extreme left and extreme
right and (right - left + 1) + (2 ^ 0 + 2 ^ 1 .... + 2 ^ (deepest - 1)).

*/