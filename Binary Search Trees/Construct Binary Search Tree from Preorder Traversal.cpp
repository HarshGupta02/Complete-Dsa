class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack<TreeNode*>stk;
        TreeNode* head = new TreeNode(preorder[0]); 
        stk.push(head);
        for(int i = 1; i < n ; i ++){
            int curr = preorder[i];
            TreeNode* temp = new TreeNode(curr);
            if(curr < stk.top() -> val){
                stk.top() -> left = temp;
                stk.push(temp);
            }else{
                TreeNode* prev = stk.top();
                stk.pop();
                while(!stk.empty() and stk.top() -> val < curr){
                    prev = stk.top();
                    stk.pop();
                }
                prev -> right = temp;
                stk.push(temp);
            }
        }
        return head;
    }
};