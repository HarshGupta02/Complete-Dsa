class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
        if(root == NULL) return NULL;
        if(root -> data >= k) return deleteNode(root -> left, k);
        root -> right = deleteNode(root -> right, k);
        return root; /// we always return a node which which have both left and right subtree's value < k
    }
};