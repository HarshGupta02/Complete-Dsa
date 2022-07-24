class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int ans = INT_MAX;
    void f(Node* root , int &k){
        if(root == NULL) return;
        if(root -> left == NULL and root -> right == NULL){
            k --;
            if(k == 0) ans = min(ans,root -> data);
            return;
        }
        f(root -> left,k);
        k --;
        if(k == 0) ans = min(ans,root -> data);
        f(root -> right,k);
    }
    
    int KthSmallestElement(Node *root, int k) {
        f(root,k);
        return (k <= 0) ? ans : -1;
    }
};