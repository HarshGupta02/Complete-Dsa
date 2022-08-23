class Solution {
public:
    
    bool f(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL and node2 == NULL) return true;
        if(node1 == NULL or node2 == NULL) return false;
        if(node1 -> val != node2 -> val) return false;
        return (f(node1 -> left, node2 -> right) and f(node1 -> right, node2 -> left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return f(root -> left, root -> right);
    }
};