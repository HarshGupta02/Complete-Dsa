class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int f(Node* root ,int &ans){
        if(root == NULL) return -1;
        if(root -> left == NULL and root -> right == NULL){
            return 0;
        }
        int max_depth;
        int left = f(root -> left,ans);
        int right = f(root -> right,ans);
        max_depth = max(left,right);
        ans = max(ans , left + 1 + right + 1 + 1);
        return max_depth + 1;
    }
    
    int diameter(Node* root) {
        if(root == NULL) return 0;
        int ans = 1;
        int x = f(root,ans);
        return ans;
    }
};