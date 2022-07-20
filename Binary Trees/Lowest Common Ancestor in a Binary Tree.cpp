/*
Here we used the concept that we try to return those numbers whose lca we need to
find and if a node has both such numbers other than null then the current root
is the lca. we used dfs here because it will provide with deepest lca possible
without returning to upper nodes.
*/

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root == NULL or root -> data == n1 or root -> data == n2) return root;
        Node* left_node = lca(root -> left,n1,n2);
        Node* right_node = lca(root -> right,n1,n2);
        if(left_node == NULL and right_node == NULL) return NULL;
        if(left_node == NULL) return right_node;
        if(right_node == NULL) return left_node;
        return root;
    }
};