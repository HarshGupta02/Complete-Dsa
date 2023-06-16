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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        while(curr != NULL or !stk.empty()) {
            if(curr != NULL) {
                stk.push(curr);
                curr = curr -> left;
            }else {
                TreeNode* temp = stk.top() -> right;
                if(temp != NULL) curr = temp;
                else {
                    temp = stk.top(); stk.pop();
                    postOrder.push_back(temp -> val);
                    while(!stk.empty() and temp == (stk.top() -> right)) {
                        temp = stk.top(); stk.pop();
                        postOrder.push_back(temp -> val);
                    }
                }
            }
        }
        return postOrder;
    }
};