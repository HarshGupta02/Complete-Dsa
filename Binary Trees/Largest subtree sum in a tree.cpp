class Solution {
  public:
    // Function to find largest subtree sum.
    
    int f(Node* root,int &ans){
        if(root == NULL) return 0;
        int curr = 0;
        curr = f(root -> left,ans) + f(root -> right,ans) + root -> data;
        ans = max(ans , curr);
        return curr;
    }
    
    int findLargestSubtreeSum(Node* root)
    {
        int ans = 0;
        int x = f(root,ans);
        return ans;
    }
};