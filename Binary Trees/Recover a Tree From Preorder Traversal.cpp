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
here we use the concept that we first of all insert the root. then for each node value that
we encounter, we see that if the top of stack can be the parent or not. for that the 
size of stack should be less than the no of dashes of current node. if yes, then we see 
which child of the parent can the current node be - left or right. until the level of node is
not less than size of stack till then we keep on popping elements from the stack and after
finding, we insert the element or node into the stack.

since it is preorder traversal then if we are popping any node from stack so they will never 
be considered again.

*/

class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int n = s.size();
        stack<TreeNode*> stk;
        int i = 0;
        while(i < n) {
            int level = 0;
            while(i < n and s[i] == '-') {
                i ++;
                level ++;
            }
            int val = 0;
            while(i < n and s[i] >= '0' and s[i] <= '9') {
                val = 10 * val + (s[i] - '0');
                i ++;
            }
            TreeNode* node = new TreeNode(val);
            if(stk.empty()) stk.push(node);
            else {
                while(!stk.empty() and level < stk.size()) stk.pop();
                if(stk.top() -> left) stk.top() -> right = node;
                else stk.top() -> left = node;
                stk.push(node);
            }
        }
        while(stk.size() > 1) stk.pop();
        return stk.top();
    }
};