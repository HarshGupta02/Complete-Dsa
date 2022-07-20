class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/

    int d_a,d_b,d_lca;
    
    Node* lca(Node* root , int a, int b){
        if(root == NULL or root -> data == a or root -> data == b) return root;
        Node* left_node = lca(root -> left,a,b);
        Node* right_node = lca(root -> right,a,b);
        if(left_node == NULL and right_node == NULL) return NULL;
        if(left_node == NULL) return right_node;
        if(right_node == NULL) return left_node;
        return root;
    }
    
    void depth(Node* root , int curr , int a , int b,int val){
        if(root == NULL) return;
        if(root -> data == a) d_a = curr; if(root -> data == b) d_b = curr; if(root -> data == val) d_lca = curr;
        depth(root -> left, curr + 1, a, b, val);
        depth(root -> right, curr + 1, a, b, val);
    }
    
    
    int findDist(Node* root, int a, int b) {
        Node* lca_node = lca(root,a,b);
        int val = lca_node -> data;
        depth(root,0,a,b,val);
        return d_a + d_b - 2 * d_lca;
    }
};