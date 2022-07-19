class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL) return;
        Node* p1 = node -> left , *p2 = node -> right;
        node -> left = p2; node -> right = p1;
        mirror(node -> left);
        mirror(node -> right);
    }
};