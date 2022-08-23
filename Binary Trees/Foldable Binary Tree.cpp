/*
TIME = O(N), SPACE = O(HEIGHT OF TREE).

here the folding condition is checked for each node of the tree , recursively
for left and right subtree. folding ensures that if we fold around a root node so
the left subtree of the root should overlap with the right subtree of the root
and vice versa.

*/

bool f(Node* node1, Node* node2){
    if(node1 == NULL and node2 == NULL) return true;
    if(node1 == NULL or node2 == NULL) return false;
    return (f(node1 -> left, node2 -> right) and f(node1 -> right, node2 -> left));
}

bool IsFoldable(Node* root)
{
    if(root == NULL) return true;
    return f(root -> left, root -> right);
}